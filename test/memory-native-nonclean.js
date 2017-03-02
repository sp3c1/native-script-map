'use strict';
var start = process.memoryUsage();
const addon = require('../build/Release/addon');
var obj = new addon.stringLowLevelLibWrapper();
var timeStart = Date.now()

let index = 0;
while (index < 200) {

    obj.add("");
    for (let i = 0; i < 100000; i++) {
        obj.append(index, "lorem ipsum");

    }

    index++;
}
var stop = process.memoryUsage();
var timeStop = Date.now()

console.log("================Native without cleaning");
console.log('rss :', Math.round(((stop.rss - start.rss) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('heapTotal :', Math.round(((stop.heapTotal - start.heapTotal) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('heapUsed :', Math.round(((stop.heapUsed - start.heapUsed) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('time :', timeStop - timeStart + " MS");