//
//  LKEncryptHelper.h
//  LKGameStatistics
//
//  Created by Madoka on 16/12/8.
//  Copyright © 2016年 Madoka. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LKEncryptHelper : NSObject
/**
 *  rsa加密
 */
- (NSString *)encryptWithString:(NSString *)content andPublicKey:(NSString *)publicKey;
/**
 *  aes加密
 */
- (NSString *)AESEncryptWithString:(NSString *)content andKey:(NSString *)key andIv:(NSString *)iv;
/**
 *  aes解密
 */
- (NSString *)AESDecryptWithString:(NSString *)content andKey:(NSString *)key andIv:(NSString *)iv;

@end
