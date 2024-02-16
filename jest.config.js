module.exports = {
    testEnvironment: "node",
    testRegex: "tests/.*\\.res\\.js$",
    transformIgnorePatterns: ["node_modules/(?!(rescript|@glennsl/rescript-jest)/)"],
};
