const addon = require('./build/Release/addon');

console.log(addon);

var obj = new addon.stringLowLevelLibWrapper();
var index = obj.add("x");
var index_b = obj.add("y");
console.log(index);
console.log(obj.append(index, "lol"));
console.log(obj.get(index));
console.log(obj);

console.log('====================== add second');
//var index_b = obj.add("y");
console.log(obj.get(index));
console.log(obj.get(index_b));
console.log(index);
console.log(index_b);
console.log('====================== remove first');
console.log(obj.remove(index));
console.log(obj.get(index_b));
console.log('====================== checking both');
try {
    console.log(obj.get(index));
    shouldNotReachHere();
} catch (e) {

}
console.log(obj.get(index_b));
console.log('====================== clear');
console.log(obj.clear());
try {
    console.log(obj.get(index_b));
    shouldNotReachHere();
} catch (e) {}
console.log(obj.size());
console.log('====================== regex');
var index_c = obj.add("abcasdfasabc");
try {
    console.log(obj.get(index_c));
    console.log(obj.regex(index_c, "/abc/gi"));
    console.log(obj.regex(index_c, "abc"));
    console.log(obj.regex(index_c, "a"));
    console.log(obj.regex(index_c, ""));
    console.log(obj.regex(index_c, 0));
    console.log(obj.regex(index_c, 123));
    console.log(obj.regex(index_c, xx));
} catch (e) {
    console.log('+++++++++++++++++catch', e);
}
console.log('====================== sizeAt');
console.log(obj.sizeAt(index_c));
console.log('====================== chunk');
console.log(obj.chunk(index_c, 0, 2));
console.log('====================== exceptions');
try {
    console.log(obj.remove(12345));
    console.log('------------remove wrong++++++++++++++');
} catch (e) {
    console.log('++++++++++++remove wrong++++++++++++++');
    console.log(e);
}

try {
    console.log(obj.add());
    console.log('------------add empty++++++++++++++');
} catch (e) {
    console.log('++++++++++++add empty++++++++++++++');
    console.log(e);
}

try {
    console.log(obj.append());
    console.log('-------------append empty+++++++++++++');
} catch (e) {
    console.log('+++++++++++++append empty+++++++++++++');
    console.log(e);
}

try {
    console.log(obj.get());
    console.log('-------------get empty+++++++++++++');
} catch (e) {
    console.log('+++++++++++++get empty+++++++++++++');
    console.log(e);
}

try {
    console.log(obj.remove());
    console.log('-------------remove empty+++++++++++++');
} catch (e) {
    console.log('+++++++++++++remove empty+++++++++++++');
    console.log(e);
}

try {
    console.log(obj.chunk());
    console.log('------------chunk empty++++++++++++++');
} catch (e) {
    console.log('++++++++++++chunk empty++++++++++++++');
    console.log(e);
}

try {
    console.log(obj.chunk(index, 6000, 7000));
    console.log('------------chunk non existing++++++++++++++');
} catch (e) {
    console.log('++++++++++++chunk non existing++++++++++++++');
    console.log(e);
}

try {
    console.log(obj.chunk(index_c, 6000, 7000));
    console.log('------------chunk out of range++++++++++++++');
} catch (e) {
    console.log('++++++++++++chunk out of range++++++++++++++');
    console.log(e);
}
console.log('oi');
try {
    console.log(obj.chunk(index_c, 8000, 7000));
    console.log('------------bad range++++++++++++++');
} catch (e) {
    console.log('++++++++++++bad range++++++++++++++');
    console.log(e);
}


console.log('++++++++++++hat As++++++++++++++');
console.log(obj.hasIndex(index_c));
console.log(obj.hasIndex(index));