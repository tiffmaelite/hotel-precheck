from collections import namedtuple
import re

JAVACOMMENT = "Javadoc-style_comment"
QTCOMMENT = "Qtdoc-style_comment"
COMMENT = "comment"
BRIEFCOMMENT = "brief_comment"
STRING = "string"
ELEMENT = "element"
BLOCK_START = "block_start"
BLOCK_END = "block_end"
CHAR = "char"
KEYWORD = "keyword"
EOL = "end_of_line"
IMPORT = "import"

def is_comment(token_type):
	return token_type == COMMENT or token_type == QTCOMMENT or token_type == JAVACOMMENT or token_type == BRIEFCOMMENT

def is_import(token_type):
	return token_type == IMPORT

def is_eol(token_type):
	return token_type == EOL

def is_keyword(token_type):
	return token_type == KEYWORD

def is_element(token_type):
	return token_type == ELEMENT

def is_char(token_type):
	return token_type == CHAR

def is_string(token_type):
	return token_type == STRING

def is_block_start(token_type):
	return token_type == BLOCK_START

def is_block_end(token_type):
	return token_type == BLOCK_END


class LexerError(Exception):
    def __init__(self, msg, idx):
        Exception.__init__(self, msg)
        self.idx = idx


Token = namedtuple("Token", ["type", "value", "idx"])


class Tokenizer(object):
    def __init__(self, token_type, rx):
        self.token_type = token_type
        self.rx = rx

    def __call__(self, lexer, match):
        lexer.append_token(self.token_type, match.group(0))


class Lexer(object):
    def __init__(self, text):
        self.tokenizers = [
            Tokenizer(QTCOMMENT, re.compile(r"/\*!.*?\*/", re.DOTALL)),
            Tokenizer(JAVACOMMENT, re.compile(r"/\*\*.*?\*/", re.DOTALL)),
            Tokenizer(BRIEFCOMMENT, re.compile(r"//.*$", re.MULTILINE)),
            Tokenizer(COMMENT, re.compile(r"/\*.*?\*/", re.DOTALL)),
            Tokenizer(STRING, re.compile(r'("([^\\"]|(\\.))*")')),
            Tokenizer(BLOCK_START, re.compile("{")),
            Tokenizer(BLOCK_END, re.compile("}")),
            Tokenizer(IMPORT, re.compile("^import .*$", re.MULTILINE)),
            Tokenizer(KEYWORD, re.compile("(default\s+property|property|function|signal)")),
            Tokenizer(ELEMENT, re.compile(r"\w[\w.<>]*")),
            Tokenizer(CHAR, re.compile(".")),
            Tokenizer(EOL, re.compile("\n")),
            ]
        self.text = text
        self.idx = 0
        self.tokens = []


    def tokenize(self):
        while True:
            self.advance()
            if self.idx == len(self.text):
                break
            self.apply_tokenizers()


    def advance(self):
        while self.idx < len(self.text):
            if self.text[self.idx].isspace():
                self.idx += 1
            else:
                break


    def apply_tokenizers(self):
        for tokenizer in self.tokenizers:
            match = tokenizer.rx.match(self.text, self.idx)
            if match:
                tokenizer(self, match)
                self.idx = match.end(0)
                return
        raise LexerError("No lexer matched", self.idx)


    def append_token(self, type, value):
        self.tokens.append(Token(type, value, self.idx))
