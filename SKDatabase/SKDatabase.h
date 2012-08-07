// Copyright 2011-2012 Jason Whitehorn
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

@property (nonatomic, retain) id<SKDatabaseDelegate> delegate;
@property sqlite3 *dbh;
@property BOOL dynamic;

/*
 * Initializes the DB with the name of a database file bundled with the application.
 */
- (id)initWithFile:(NSString *)dbFile;

/*
 * Initializes the DB with the contents of an NSData, and writes it's contents out to the specified file.
 */
- (id)initWithData:(NSData *)data andFile:(NSString *)dbFile;

/*
 * Close the database connect.
 */
- (void)close;

/*
 * Executes the supplied SQL, and returns a single column.
 */
- (id)lookupColForSQL:(NSString *)sql;

/*
 * Executes the supplied SQL, and returns a single row.
 */
- (NSDictionary *)lookupRowForSQL:(NSString *)sql;

/*
 * Executes the supplied SQL, and returns everything.
 */
- (NSArray *)lookupAllForSQL:(NSString *)sql;

/*
 * Escape a string. Useful for preparing SQL statements.
 */
- (NSString *)escapeString:(NSString *)dirtyString;

@end



