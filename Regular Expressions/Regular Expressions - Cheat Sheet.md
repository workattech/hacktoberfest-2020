# Regular Expressions - Cheat Sheet

* use a single `|` to say 'or'
* `[ ]` - says any of the characters inside the brackets
* `?` make the preceding token optional
* `.+` - matches all characters to the end of the line
* use parentheses to group characters as using the `|` alone divide the regex into only a left and right side.
* `^` matches only if it's at the beginning of a string
* `$` matches only if it's the end of a string
* `+` is greedy - it won't just get the next token. it will keep searching until it reaches the last one.
* `+?` is not greedy - it will just search to the next occurrence of a token.
* `{3}` - would match 3 occurrences of the preceding token
* `{3,4}` - could match the range of 3 to 4 characters of the preceding token

## Flags
* `\w` - matches any word character
* `\r` = carriage return
* `\n` = new lines
* `\s` = space characters
* `\w` = word character
* `\d` = digits 0-9

## Lookahead and Lookbehind
* `(?<!`  = negative look behind
* `(?<=`  = positive look behind
* `(?=`  = positive look ahead 
* `(?!`  = negative look ahead

## JavaScript Methods
* `RegExp.exec(string)` = Applies the RegExp to the given string, and returns the match information.
* `RegExp.test(string)` = Tests if the given string matches the Regexp, and returns true if matching, false if not.
* `String.match(pattern)` = Matches given string with the RegExp. With g flag returns an array containing the matches, without g flag returns just the first match or if no match is found returns null.
* `String.search(pattern)` = Matches RegExp with string and returns the index of the beginning of the match if found, -1 if not.
* `String.replace(pattern,string)` = Replaces matches with the given string, and returns the edited string.
* `String.split(pattern)` = Cuts a string into an array, making cuts at matches.