'use strict';
var mocha = require('mocha');
var expect = require('expect');

const addon = require('../build/Release/addon');

var obj = new addon.stringLowLevelLibWrapper();

let index = 0;
let indexSecondary = 0;

describe('Native String Lookup Map', function() {
    it('should be empty map', function() {
        expect(obj.size()).toBe(0);
    });

    it('add element', function() {
        index = obj.add('xxx');
        expect(obj.size()).toBe(1);
        expect(index).toNotBe(0);
        expect(obj.hasIndex(index)).toBe(true);
        expect(obj.get(index)).toBe('xxx');
        expect(obj.sizeAt(index)).toBe(3);
    });

    it('append element', function() {
        let indexCheck = obj.append(index, "x");
        expect(indexCheck).toBe(true);
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

        let get = () => {
            return obj.get(index)
        };
        expect(get).toThrow("Can not retrive element");

        let chunk = () => {
            return obj.chunk(index, 1, 2);
        };
        expect(chunk).toThrow("Chunking exception");

        expect(obj.append(index, "ow No")).toBe(false);

        let sizeAt = () => {
            return obj.sizeAt(index);
        };

        expect(sizeAt).toThrow("Element does not exists");
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
        console.log(index, indexSecondary);
        //expect(obj.size()).toBe(2);
        expect(index).toNotBe(0);
        expect(indexSecondary).toNotBe(0);
        expect(indexSecondary).toNotBe(index);
        expect(obj.hasIndex(index)).toBe(true);
        expect(obj.hasIndex(indexSecondary)).toBe(true);
        expect(obj.get(index)).toBe('abc');
        expect(obj.get(indexSecondary)).toBe('zyxw');
        expect(obj.sizeAt(index)).toBe(3);
        expect(obj.sizeAt(indexSecondary)).toBe(4);
    });

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});

    it('', function() {});
});