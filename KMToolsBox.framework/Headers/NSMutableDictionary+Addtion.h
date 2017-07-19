//
//  NSMutableDictionary+Addtion.h
//  OKSDKLK
//
//  Created by Madoka on 17/4/28.
//  Copyright © 2017年 zxq. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (Addtion)
/**
 *  如果值为空则自动转化为@""
 */
- (void)setInstance:(id)instance ForKey:(NSString *)key;
@end
