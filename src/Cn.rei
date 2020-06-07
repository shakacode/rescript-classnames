let (+): (string, string) => string;
let none: string;
let on: (string, bool) => string;
let onSome: (string, option('a)) => string;
let mapSome: (option('a), 'a => string) => string;
let take: option(string) => string;
let onOk: (string, result('a, 'b)) => string;
let mapOk: (result('a, 'b), 'a => string) => string;
let onErr: (string, result('a, 'b)) => string;
let mapErr: (result('a, 'b), 'b => string) => string;

[@deprecated "Use Cn.(a + b + c)"]
let make: list(string) => string;
[@deprecated "Use Cn.on"]
let ifTrue: (string, bool) => string;
[@deprecated "Use Cn.onSome"]
let ifSome: (string, option('a)) => string;
[@deprecated "Use Cn.take"]
let unpack: option(string) => string;
