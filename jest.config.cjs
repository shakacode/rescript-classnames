module.exports = {
    testEnvironment: "node",
    testRegex: "tests/.*\\.res\\.js$",
    transformIgnorePatterns: ["node_modules/(?!(rescript|@rescript/runtime|@glennsl/rescript-jest)/)"],
};
