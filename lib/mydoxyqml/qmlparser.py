import lexer

from qmlclass import QmlArgument, QmlProperty, QmlFunction, QmlSignal

JAVADOCMARKER = "@"
QTDOCMARKER = "\\"

class QmlParserError(Exception):
    def __init__(self, msg, token):
        Exception.__init__(self, msg)
        self.token = token


class QmlParserUnexpectedTokenError(QmlParserError):
    def __init__(self, token):
        QmlParserError.__init__(self, "Unexpected token: %s" % str(token), token)


def parse_class_definition(reader, cls, docmarker):
    token = reader.consume_wo_comments()
    if not lexer.is_block_start(token.type):
        raise QmlParserError("Expected '{' after base class name", token)
    comments = []
    while not reader.at_end():
        token = reader.consume()
        if(lexer.is_comment(token.type)):
			if token.type == lexer.QTCOMMENT and docmarker == QTDOCMARKER:
				comments.append(token.value)
			elif token.type == lexer.JAVACOMMENT and docmarker == JAVADOCMARKER:
				comments.append(token.value)
			elif token.type == lexer.BRIEFCOMMENT:
				comments.append(token.value)	
			#else:
				#comments.append(token.value)
        else:
            done = parse_class_content(reader, cls, token, comments, docmarker)
            if done:
               return
            comments = []


def parse_class_content(reader, cls, token, comments, docmarker):
    # Use all the preceding comments
    doc = "\n".join(comments)
    if lexer.is_keyword(token.type):
        if token.value.endswith("property"):
            obj = parse_property(reader, token.value, docmarker)
            obj.doc = doc
            cls.properties.append(obj)
        elif token.value == "function":
            obj = parse_function(reader, docmarker)
            obj.doc = doc
            cls.functions.append(obj)
        elif token.value == "signal":
            obj = parse_signal(reader, docmarker)
            obj.doc = doc
            cls.signals.append(obj)
        else:
            raise QmlParserError("Unknown keyword '%s'" % token.value, token)

    elif lexer.is_block_start(token.type):
        skip_block(reader)

    elif lexer.is_block_end(token.type):
        return True

    return False


def parse_property(reader, property_token_value, docmarker):
    prop = QmlProperty(docmarker)
    prop.is_default = property_token_value.startswith("default")

    token = reader.consume_expecting(lexer.ELEMENT)
    prop.type = token.value

    token = reader.consume_expecting(lexer.ELEMENT)
    prop.name = token.value
    return prop


def parse_function(reader, docmarker):
    obj = QmlFunction(docmarker)
    token = reader.consume_expecting(lexer.ELEMENT)
    obj.name = token.value

    reader.consume_expecting(lexer.CHAR, "(")
    obj.args = parse_arguments(reader, docmarker, typed=False)
    reader.consume_expecting(lexer.CHAR, "{")
    obj.content = get_block(reader)
    return obj


def parse_signal(reader, docmarker):
    obj = QmlSignal()
    token = reader.consume_expecting(lexer.ELEMENT)
    obj.name = token.value

    idx = reader.idx
    token = reader.consume_wo_comments()
    if lexer.is_char(token.type) and token.value == "(":
        obj.args = parse_arguments(reader, docmarker, typed=True)
        obj.content = parse_signal_reception(reader, token.value)
    else:
        reader.idx = idx
    return obj


def parse_signal_reception(reader, signal_name):
	if not signal_name:
		return
	elif len(signal_name) == 0:
		return ""
	else:
		reception_content=""
	    idx = reader.idx
		receiver_name = "on%s%s" % (signal_name[:1].upper(),signal_name[1:])
		while not reader.at_end():
            token = reader.consume()
            if lexer.is_string(token.type) and token.value==receiver_name:
				reader.consume_expecting(lexer.CHAR, ":")
				token = reader.consume()
				if lexer.is_block_start(token.type):
					reception_content = get_block(reader)
				else:
					reception_content = consume_line(reader)
				reader.idx = idx
				return reception_content
	return ""


def parse_arguments(reader, docmarker, typed=False):
    token = reader.consume_wo_comments()
    if lexer.is_char(token.type) and token.value == ")":
        return []
    elif not lexer.is_element(token.type):
        raise QmlParserUnexpectedTokenError(token)

    args = []
    while True:
        if typed:
            arg_type = token.value
            token = reader.consume_expecting(lexer.ELEMENT)
            arg = QmlArgument(token.value)
            arg.type = arg_type
        else:
            arg = QmlArgument(token.value)
        args.append(arg)

        token = reader.consume_expecting(lexer.CHAR)
        if token.value == ")":
            return args
        elif token.value != ",":
            raise QmlParserUnexpectedTokenError(token)

        token = reader.consume_expecting(lexer.ELEMENT)


def skip_block(reader):
    count = 1
    while True:
        token = reader.consume_wo_comments()
        if lexer.is_block_start(token.type):
            count += 1
        elif lexer.is_block_end(token.type):
            count -= 1
            if count == 0:
                return
                

def get_block(reader):
    count = 1
    content = ""
    while True:
        token = reader.consume_wo_comments()
        content += token.value
        if lexer.is_block_start(token.type):
            count += 1
        elif lexer.is_block_end(token.type):
            count -= 1
            if count == 0:
                return content


def parse_header(reader, cls):
    while not reader.at_end():
        token = reader.consume()
        if lexer.is_comment(token.type):
            cls.comments.append(token.value)
        elif lexer.is_import(token.type):
            pass
        elif lexer.is_element(token.type):
            cls.base_name = token.value
            return
        else:
            raise QmlParserUnexpectedTokenError(token)


class TokenReader(object):
    def __init__(self, tokens):
        self.tokens = tokens
        self.idx = 0

    def consume(self):
        token = self.tokens[self.idx]
        self.idx += 1
        return token
    
    def consume_line(self):
	    token =""
	    while True:
			tok = consume(self)
			token += tok
			if tok == lexer.is_eol(tok.type):
				return token

    def consume_wo_comments(self):
        while True:
            token = self.consume()
            if not lexer.is_comment(token.type):
                return token

    def consume_expecting(self, type, value=None):
        token = self.consume_wo_comments()
        if token.type != type:
            raise QmlParserError("Expected token of type '%s', got '%s' instead" % (type, token.type), token)
        if value is not None and token.value != value:
            raise QmlParserError("Expected token with value '%s', got '%s' instead" % (value, token.value), token)
        return token

    def at_end(self):
        return self.idx == len(self.tokens)


def parse(tokens, cls, docmarker):
    reader = TokenReader(tokens)
    parse_header(reader, cls)
    parse_class_definition(reader, cls, docmarker)
