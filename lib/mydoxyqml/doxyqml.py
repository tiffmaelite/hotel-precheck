#!/usr/bin/env python
import logging
import os
import sys
from optparse import OptionParser

import qmlparser
from lexer import Lexer, LexerError
from qmlclass import QmlClass


VERSION = "0.1.0"
DESCRIPTION = "Doxygen input filter for QML files"


def coord_for_idx(text, idx):
    head, sep, tail = text[:idx].rpartition("\n")
    if sep == "\n":
        row = head.count("\n") + 2
    else:
        row = 1
    col = len(tail) + 1
    return row, col


def line_for_idx(text, idx):
    bol = text.rfind("\n", 0, idx)
    if bol == -1:
        bol = 0
    eol = text.find("\n", idx)
    return text[bol:eol]


def info_for_error_at(text, idx):
    row, col = coord_for_idx(text, idx)
    line = line_for_idx(text, idx)
    msg = line + "\n" + "-" * (col - 1) + "^"
    return row, msg


def create_opt_parser():
    parser = OptionParser(
        usage="usage: %prog [options] <path/to/File.qml>",
        version="%prog " + VERSION,
        description=DESCRIPTION,
        )
    parser.add_option("-d", "--debug",
                      action="store_true", dest="debug", default=False,
                      help="Log debug info to stderr")
    parser.add_option("-q", "--qt",
                      action="store_true", dest="qtdoc", default=False,
                      help="Inform parser that documentation is QtDoc style")
    parser.add_option("-j", "--java",
                      action="store_true", dest="javadoc", default=True,
                      help="Inform parser that documentation is Javadoc style (default)")                      
    return parser


def main():
    opt_parser = create_opt_parser()
    options, args = opt_parser.parse_args()
	
    if len(args) != 1:
        opt_parser.error("Invalid number of arguments")
    else:
        name = args[0]
        if options.qtdoc:
            docmarker=qmlparser.QTDOCMARKER
        elif options.javadoc: #default
            docmarker=qmlparser.JAVADOCMARKER
		
    text = open(name).read()

    lexer = Lexer(text)
    try:
        lexer.tokenize()
    except LexerError, exc:
        logging.error("Failed to tokenize %s" % name)
        row, msg = info_for_error_at(text, exc.idx)
        logging.error("Lexer error line %d: %s\n%s", row, exc, msg)
        if options.debug:
            raise
        else:
            return -1

    if options.debug:
        for token in lexer.tokens:
			if not lexer.is_eol(token.type):
				print "## type=%s ####" % token.type
                print token.value

    classname = os.path.basename(name).split(".")[0]
    qml_class = QmlClass(classname)

    try:
        qmlparser.parse(lexer.tokens, qml_class, docmarker)
    except qmlparser.QmlParserError, exc:
        logging.error("Failed to parse %s" % name)
        row, msg = info_for_error_at(text, exc.token.idx)
        logging.error("Lexer error line %d: %s\n%s", row, exc, msg)
        if options.debug:
            raise
        else:
            return -1

    print qml_class

    return 0


if __name__ == "__main__":
    sys.exit(main())
# vi: ts=4 sw=4 et
