// Copyright 2011 Jason Whitehorn
// Released under the terms of the license found
// in the license.txt in the root of the project

// Based on works originally found @
// http://iphoneinaction.manning.com/iphone_in_action/2009/07/skdatabase-11-a-sqlite-library-for-the-iphone.html
// Unfortunantly that website is no longer around.
// If memory serves me correctly the original author
// released it into the public domain.

#import <UIKit/UIKit.h>
#import <sqlite3.h>

@protocol SKDatabaseDelegate <NSObject>
@optional
- (void)databaseTableWasUpdated:(NSString *)table;
@end

@interface SKDatabase : NSObject {
	
	id<SKDatabaseDelegate> delegate;
	sqlite3 *dbh;
	BOOL dynamic;
}

@property (assign) id<SKDatabaseDelegate> delegate;
@property sqlite3 *dbh;
@property BOOL dynamic;

- (id)initWithFile:(NSString *)dbFile;
- (id)initWithReadOnlyFile:(NSString *)dbFile;
- (id)initWithData:(NSData *)data andFile:(NSString *)dbFile;

- (void)close;

- (sqlite3_stmt *)prepare:(NSString *)sql;

- (id)lookupColForSQL:(NSString *)sql;
- (NSDictionary *)lookupRowForSQL:(NSString *)sql;
- (NSArray *)lookupAllForSQL:(NSString *)sql;

- (int)lookupCountWhere:(NSString *)where forTable:(NSString *)table;
- (int)lookupMax:(NSString *)key Where:(NSString *)where forTable:(NSString *)table;
- (int)lookupSum:(NSString *)key Where:(NSString *)where forTable:(NSString *)table;

- (void)insertArray:(NSArray *)dbData forTable:(NSString *)table;
- (void)insertDictionary:(NSDictionary *)dbData forTable:(NSString *)table;

- (void)updateArray:(NSArray *)dbData forTable:(NSString *)table;
- (void)updateArray:(NSArray *)dbData forTable:(NSString *)table where:(NSString *)where;
- (void)updateDictionary:(NSDictionary *)dbData forTable:(NSString *)table;
- (void)updateDictionary:(NSDictionary *)dbData forTable:(NSString *)table where:(NSString *)where;
- (void)updateSQL:(NSString *)sql forTable:(NSString *)table;

- (void)deleteWhere:(NSString *)where forTable:(NSString *)table;
- (void) deleteAllFrom:(NSString *)table;

- (BOOL)runDynamicSQL:(NSString *)sql forTable:(NSString *)table;

- (NSString *)escapeString:(NSString *)dirtyString;

@end



