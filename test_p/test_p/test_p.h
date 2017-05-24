//
//  test_p.h
//  test_p
//
//  Created by simple on 2017/5/24.
//  Copyright © 2017年 simple. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "JRSwizzle.h"

//! Project version number for test_p.
FOUNDATION_EXPORT double test_pVersionNumber;

//! Project version string for test_p.
FOUNDATION_EXPORT const unsigned char test_pVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <test_p/PublicHeader.h>


#define CBGetClass(classname) objc_getClass(#classname)
#define CBRegisterClass(superclassname, subclassname) { Class class = objc_allocateClassPair(CBGetClass(superclassname), #subclassname, 0);objc_registerClassPair(class); }
#define CBHookInstanceMethod(classname, ori_sel, new_sel) { NSError *error; [CBGetClass(classname) jr_swizzleMethod:ori_sel withMethod:new_sel error:&error]; if(error) NSLog(@"%@", error); }
#define CBHookClassMethod(classname, ori_sel, new_sel) { NSError *error; [CBGetClass(classname) jr_swizzleClassMethod:ori_sel withClassMethod:new_sel error:&error]; if(error) NSLog(@"%@", error); }
#define CBGetInstanceValue(obj, valuename) object_getIvar(obj, class_getInstanceVariable([obj class], #valuename))
#define CBSetInstanceValue(obj, valuename, value) object_setIvar(obj, class_getInstanceVariable([obj class], #valuename), value)

