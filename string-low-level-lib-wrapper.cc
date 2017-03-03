#include <node.h>
#include "string-low-level-lib-wrapper.h"

using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Persistent;
using v8::String;
using v8::Value;
using v8::Exception;
using v8::Boolean;

Persistent<Function> stringLowLevelLibWrapper::constructor;

stringLowLevelLibWrapper::stringLowLevelLibWrapper() {
}

stringLowLevelLibWrapper::~stringLowLevelLibWrapper() {
}

void stringLowLevelLibWrapper::Init(Local<Object> exports) {
  Isolate* isolate = exports->GetIsolate();

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "stringLowLevelLibWrapper"));
  tpl->InstanceTemplate()->SetInternalFieldCount(10);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "add", add);
  NODE_SET_PROTOTYPE_METHOD(tpl, "append", append);
  NODE_SET_PROTOTYPE_METHOD(tpl, "regex", regex);
  NODE_SET_PROTOTYPE_METHOD(tpl, "get", get);
  NODE_SET_PROTOTYPE_METHOD(tpl, "remove", remove);
  NODE_SET_PROTOTYPE_METHOD(tpl, "chunk", chunk);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "sizeAt", sizeAt);
  NODE_SET_PROTOTYPE_METHOD(tpl, "hasIndex", hasIndex);
  NODE_SET_PROTOTYPE_METHOD(tpl, "clear", clear);

  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "stringLowLevelLibWrapper"), tpl->GetFunction());
}

void stringLowLevelLibWrapper::New(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new stringLowLevelLibWrapper(...)`
    //double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    stringLowLevelLibWrapper* obj = new stringLowLevelLibWrapper();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `stringLowLevelLibWrapper(...)`, turn into construct call.
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    Local<Object> result =
        cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(result);
    //??? need to clear this?
  }
}

void stringLowLevelLibWrapper::add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  if (args.Length() != 1) {
     // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  try{

    if(!args[0]->IsString()){
      throw false;
    }

    //int index = obj->value_.pushVector(*String::Utf8Value(args[0]->ToString()));
    //int index = obj->value_.pushVector(args[0]->ToString());
    int index = obj->value_.pushVector(std::string("lol"));
    Local<Number> num = Number::New(isolate,index);

    args.GetReturnValue().Set(num);
  }catch(...){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Could not add element")));
  }
}

void stringLowLevelLibWrapper::append(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  if (args.Length() != 2) {
     // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  try{

    if (!args[1]->IsString()){
      throw false;
    }

    int index = (int)args[0]->IntegerValue();
    obj->value_.appendVector(index, *String::Utf8Value(args[1]->ToString()));
  }catch (...){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Can not append")));
    return;
  }

}

void stringLowLevelLibWrapper::get(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  if (args.Length() != 1) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

 int index = (int) args[0]->IntegerValue();

  try{
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, obj->value_.lookUpVector(index).c_str()));
  }catch(...){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Can not retrive element")));
  }
}

void stringLowLevelLibWrapper::regex(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  if (args.Length() != 2) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }  

  bool regex;
  try{
    regex = obj->value_.regexVector((int) args[0]->IntegerValue(),*String::Utf8Value(args[1]->ToString()));
  }catch(...){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Regex Exception")));
    return; 
  }

  args.GetReturnValue().Set(Boolean::New(isolate, regex));
}


void stringLowLevelLibWrapper::remove(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  if (args.Length() != 1) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  int removed = obj->value_.removeVector((int) args[0]->IntegerValue());
  
  if(removed==0){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Could not remove provided id")));
  }
  
}

void stringLowLevelLibWrapper::chunk(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() != 3) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  try{
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, obj->value_.chunkData((int) args[0]->IntegerValue(), (int) args[1]->IntegerValue(), (int)args[2]->IntegerValue()).c_str()));
  }catch(...){
     isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Chunking exception")));
  }
  
}

void stringLowLevelLibWrapper::size(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  args.GetReturnValue().Set(Number::New(isolate, obj->value_.size()));
}

void stringLowLevelLibWrapper::sizeAt(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() != 1) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  try{
    args.GetReturnValue().Set(Number::New(isolate, obj->value_.sizeAt((int) args[0]->IntegerValue())));
  }catch(...){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Element does not exists"))); 
  }
  
}

void stringLowLevelLibWrapper::hasIndex(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() != 1) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  
  args.GetReturnValue().Set(Boolean::New(isolate, obj->value_.hasAt((int) args[0]->IntegerValue())));
}

void stringLowLevelLibWrapper::clear(const FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  obj->value_.clear();
}