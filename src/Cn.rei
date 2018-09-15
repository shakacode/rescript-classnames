let make: list(string) => string;
let ifTrue: (string, bool) => string;
let ifSome: (string, option('a)) => string;
let mapSome: (option('a), 'a => string) => string;
let unpack: option(string) => string;
