const addon = require('./build/Release/addon');

console.log(addon);

var obj = new addon.stringLowLevelLibWrapper();
console.log(obj.plusOne()); // 11
console.log(obj.plusOne()); // 12
console.log(obj.plusOne()); // 13