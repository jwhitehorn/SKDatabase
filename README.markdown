SKDatabase
========

This is library is designed to help you access a SQLite database from Objective-C. 
I've only tested this on the iPhone, but I guess it should work on the Mac as well.

Based on works originally found @
http://iphoneinaction.manning.com/iphone_in_action/2009/07/skdatabase-11-a-sqlite-library-for-the-iphone.html
Unfortunantly that website is no longer around.
If memory serves me correctly the original author released it into the public domain.

Released under the terms of the associated [license](https://github.com/jwhitehorn/SKDatabase/blob/master/license.txt)


Getting Started
========

To use this library you will need to reference the libsqlite3.0.dylib library. After you've referenced that, simply add the files SKDatabase.h and SKDatabase.m to your project. I recommend creating a folder, and an appropriate group in Xcode, called SKDatabase to store those files in.

Using SKDatabase
========

The core of SKDatabase (and frankly the _only_ of SKDatabase) is the SKDatabase class. This class represents your connection to a SQLite database. To initialize your database connection use one of the following:

- `(id)initWithFile:(NSString *)dbFile`
- `(id)initWithReadOnlyFile:(NSString *)dbFile`
- `(id)initWithData:(NSData *)data andFile:(NSString *)dbFile`