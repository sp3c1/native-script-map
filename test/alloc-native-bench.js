'use strict';
var start = process.memoryUsage();
const addon = require('../build/Release/addon');
var obj = new addon.stringLowLevelLibWrapper();
var timeStart = Date.now()

for (let i = 0; i < 1000000; i++) {
    obj.add(i + "lorem ipsum " + i);
    //obj.remove(i);

}

var stop = process.memoryUsage();
var timeStop = Date.now()

console.log("================Native without cleaning", obj.size());
console.log('rss :', Math.round(((stop.rss - start.rss) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('heapTotal :', Math.round(((stop.heapTotal - start.heapTotal) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('heapUsed :', Math.round(((stop.heapUsed - start.heapUsed) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('time :', timeStop - timeStart + " MS");