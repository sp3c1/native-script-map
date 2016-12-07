const addon = require('./build/Release/addon');

console.log(addon);

var obj = new addon.stringLowLevelLibWrapper();
var index = obj.add("x");
console.log(index);
console.log(obj.append(index, "lol"));
console.log(obj.get(index));
console.log(obj);

console.log('====================== add second');
var index_b = obj.add("y");
console.log(obj.get(index));
console.log(obj.get(index_b));
console.log(index);
console.log(index_b);
console.log('====================== remove first');
console.log(obj.remove(index));
console.log(obj.get(index_b));
console.log('====================== remove not existing');
console.log(obj.remove(12345));
console.log(obj.get(index_b));
console.log('====================== checking both');
console.log(obj.get(index));
console.log(obj.get(index_b));
console.log('====================== clear');
console.log(obj.clear());
console.log(obj.get(index_b));
console.log(obj.size());
console.log('====================== exceptions');
console.log(obj.remove(12345));
console.log(obj.add());
console.log(obj.append());
console.log(obj.get());
console.log(obj.remove());
console.log(obj.chunk());
console.log(obj.chunk(123123));