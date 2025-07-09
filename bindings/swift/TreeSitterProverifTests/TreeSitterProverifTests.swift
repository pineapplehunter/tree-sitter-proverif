import XCTest
import SwiftTreeSitter
import TreeSitterProverif

final class TreeSitterProverifTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_proverif())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Proverif grammar")
    }
}
