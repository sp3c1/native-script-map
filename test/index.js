'use strict';
var mocha = require('mocha');
var expect = require('expect');

const addon = require('../build/Release/addon');

var obj = new addon.stringLowLevelLibWrapper();

let index = -1;
let indexSecondary = -1;

describe('Native String Lookup Map', function() {
    it('should be empty map', function() {
        expect(obj.size()).toBe(0);
    });

    it('add element', function() {
        index = obj.add('xxx');
        expect(index).toBe(0);
        expect(obj.hasIndex(index)).toBe(true);
        expect(obj.get(index)).toBe('xxx');
        expect(obj.size()).toBe(1);
        expect(obj.sizeAt(index)).toBe(3);
    });

    it('append element', function() {
        obj.append(index, "x");
        expect(obj.get(index)).toBe('xxxx');
        expect(obj.sizeAt(index)).toBe(4);
    });

    it('handle regex on right index', function() {

        expect(obj.regex(index, "a")).toBe(false);
        expect(obj.regex(index, "axx")).toBe(false);
        expect(obj.regex(index, "xxxxx")).toBe(false);
        expect(obj.regex(index, "x")).toBe(true);
        expect(obj.regex(index, "([ax])")).toBe(true);
        expect(obj.regex(index, "xxxx")).toBe(true);

    });


    it('handle chunking and get on right index', function() {
        expect(obj.chunk(index, 0, 4)).toBe(obj.get(index));
        expect(obj.chunk(index, 0, 2)).toBe("xx");
    });


    it('handle wrong chunking and get on right index', function() {

        let chunkWrongDimmension = () => {
            return obj.chunk(index, 4, 1);
        };
        expect(chunkWrongDimmension).toThrow("Chunking exception");

        expect(obj.chunk(index, 0, 10)).toBe('xxxx');

        expect(obj.chunk(index, 0, 0)).toBe('');

        let chunkMissingArgument = () => {
            return obj.chunk(index, 4);
        };
        expect(chunkMissingArgument).toThrow("Wrong number of arguments");

    });


    it('remove element', function() {
        obj.remove(index);
        expect(obj.size()).toBe(0);
        expect(obj.hasIndex(index)).toBe(false);

        expect(() => { obj.get(index); }).toThrow("Can not retrive element");

        expect(() => { obj.chunk(index, 1, 2) }).toThrow("Chunking exception");


        expect(() => { obj.append(index, "ow No") }).toThrow("Can not append");

        expect(() => { obj.sizeAt(index) }).toThrow("Element does not exists");
    });


    it('handle chunking and get on wrong index', function() {
        let method = () => {
            obj.chunk(index, 0, 0);
        }

        expect(method).toThrow("Chunking exception");
    });


    it('adding 2 elemnts', function() {
        index = obj.add('abc');
        indexSecondary = obj.add('zyxw');

        expect(index).toBe(1);
        expect(indexSecondary).toBe(2);
        expect(obj.hasIndex(index)).toBe(true);
        expect(obj.hasIndex(indexSecondary)).toBe(true);
        expect(obj.get(index)).toBe('abc');
        expect(obj.get(indexSecondary)).toBe('zyxw');
        expect(obj.sizeAt(index)).toBe(3);
        expect(obj.sizeAt(indexSecondary)).toBe(4);
        obj.append(index, "efg");
        obj.append(indexSecondary, "rsty");
        expect(obj.get(index)).toBe('abcefg');
        expect(obj.get(indexSecondary)).toBe('zyxwrsty');
    });

    it('more regex checks', function() {
        expect(obj.regex(index, "a")).toBe(true);
        expect(obj.regex(index, "b")).toBe(true);
        expect(obj.regex(index, "c")).toBe(true);
        expect(obj.regex(index, "([cba])")).toBe(true);
    });


    it('other exceptions', function() {
        expect(() => { obj.get() }).toThrow();
        expect(() => { obj.append() }).toThrow();
        expect(() => { obj.add() }).toThrow();
        expect(() => { obj.remove(12345) }).toThrow();
        expect(() => { obj.remove() }).toThrow();
    });

    it('clear', function() {
        obj.clear();
        expect(obj.size()).toBe(0);
    });

    it('add append funky types', function() {
        expect(() => { obj.add(null) }).toThrow();
        expect(() => { obj.add(undefined) }).toThrow();
        expect(() => { obj.add(false) }).toThrow();
        expect(() => { obj.add(123) }).toThrow();

        index = obj.add("");
        expect(index).toBe(3);
        expect(obj.size()).toBe(1);

        expect(obj.sizeAt(index)).toBe(0);

        expect(() => { obj.append(index, null) }).toThrow();
        expect(() => { obj.append(index, undefined) }).toThrow();
        expect(() => { obj.append(index, false) }).toThrow();
        expect(() => { obj.append(index, 123) }).toThrow();

        expect(obj.sizeAt(index)).toBe(0);

    });

    it('get second instance', function() {
        obj.add('a');
        var objSecond = new addon.stringLowLevelLibWrapper();

        expect(obj.size()).toBe(2);
        expect(objSecond.size()).toBe(0);

        objSecond.add("test");

        expect(obj.size()).toBe(2);
        expect(objSecond.size()).toBe(1);

        objSecond.add("test");
        expect(obj.size()).toBe(2);
        expect(objSecond.size()).toBe(2);

        obj.clear();
        expect(obj.size()).toBe(0);
        expect(objSecond.size()).toBe(2);

        objSecond.clear();
        expect(obj.size()).toBe(0);
        expect(objSecond.size()).toBe(0);


    });


});