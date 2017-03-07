'use strict';

var testString = [];
var start = process.memoryUsage();
var timeStart = Date.now();
var index = 0;
while (index < 200) {

    for (let i = 0; i < 100000; i++) {
        testString[index] = testString[index] + "lorem ipsum";
    }

    index++;
}
var stop = process.memoryUsage();
var timeStop = Date.now()

console.log("================JS without cleaning");
console.log('rss :', Math.round(((stop.rss - start.rss) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('heapTotal :', Math.round(((stop.heapTotal - start.heapTotal) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('heapUsed :', Math.round(((stop.heapUsed - start.heapUsed) / 1024 / 1024) * 10000) / 10000 + " MB");
console.log('time :', timeStop - timeStart + " MS");