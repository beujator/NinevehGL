/*
 *	NGLRuntime.h
 *	
 *	The NinevehGL Engine is a free 3D engine to work with OpenGL programmable pipeline, made with pure
 *	Objective-C for iOS (iPhone, iPad and iPod Touch). NinevehGL is prepared to import 3D file with the
 *	formats:
 *		- WaveFront OBJ file (.obj);
 *		- COLLADA file (.dae).
 *
 *	More information at the official web site: http://nineveh.gl
 *
 *  Created by Diney Bomfim on 7/13/11.
 *  Copyright (c) 2010 DB-Interactively. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark -
#pragma mark Basic Definitions
#pragma mark -
//**********************************************************************************************************
//
//	Basic Definitions
//
//**********************************************************************************************************

#pragma mark -
#pragma mark NinevehGL Definitions
//**************************************************
//	NinevehGL Definitions
//**************************************************

// Basic definition to identify the presence of NinevehGL.
#define NINEVEHGL

// NinevehGL current version.
#define NGL_VERSION				0.94f

// NinevehGL supports Multithreading.
#define NGL_MULTITHREADING

// NinevehGL max parsing threads.
#define NGL_THREAD_SLOTS		5

#pragma mark -
#pragma mark iOS Definitions
//**************************************************
//	iOS Definitions
//**************************************************

// Checks for iOS 4 or above.
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
	
	// Prevents compiling for iOS 3.x or earlier.
	#error NinevehGL only works with iOS 4.0 and later.

#endif

#pragma mark -
#pragma mark Compiler Definitions
//**************************************************
//	Compiler Definitions
//**************************************************

// Defines the NinevehGL static functions. The Inline instructions is a little bit more expensive.
#define NGL_INLINE				static inline

// Defines the NinevehGL debug mode for the simulator.
//#if TARGET_IPHONE_SIMULATOR
#ifdef DEBUG

	// Enables the debug mode only in the simulator.
	#define NGL_DEBUG

#endif

// Defines the ARC instructions, ONLY FOR PUBLIC HEADERS. NinevehGL is always compiled using MMC.
#if __has_feature(objc_arc)

	// ARC definition.
	#define NGL_ARC

	// Equivalent to MMC "assign".
	#define NGL_ARC_UNSAFE		__unsafe_unretained
	#define NGL_ARC_BRIDGE		__bridge
	#define NGL_ARC_ASSIGN		__weak
	#define NGL_ARC_RETAIN		__strong

	// Property definitions
	#define NGL_RETAIN			strong
	#define NGL_ASSIGN			weak
	#define NGL_COPY			copy

#else
	
	// Nothing is defined for non-ARC compilers.
	#define NGL_ARC_UNSAFE
	#define NGL_ARC_BRIDGE
	#define NGL_ARC_ASSIGN
	#define NGL_ARC_RETAIN

	// Property definitions
	#define NGL_RETAIN			retain
	#define NGL_ASSIGN			assign
	#define NGL_COPY			copy

#endif

#pragma mark -
#pragma mark C/C++ Definitions
//**************************************************
//	C/C++ Definitions
//**************************************************

// Defines the C/C++ extern patterns
#ifdef __cplusplus

	// Extern instruction for C++ code.
	#define NGL_API				extern "C" __attribute__((visibility ("default")))

#else

	// Extern instruction for C code.
	#define NGL_API				extern __attribute__((visibility ("default")))

#endif

#pragma mark -
#pragma mark Data Type Definitions
#pragma mark -
//**********************************************************************************************************
//
//	Data Type Definitions
//
//**********************************************************************************************************

// NinevehGL NULL value.
#define NGL_NULL				0x00

// NinevehGL correlated data types.
#define NGL_FLOAT				0x01
#define NGL_INT					0x02
#define NGL_BOOL				0x03
#define NGL_VEC2				0x04
#define NGL_VEC3				0x05
#define NGL_VEC4				0x06
#define NGL_IVEC2				0x07
#define NGL_IVEC3				0x08
#define NGL_IVEC4				0x09
#define NGL_BVEC2				0x0A
#define NGL_BVEC3				0x0B
#define NGL_BVEC4				0x0C
#define NGL_MAT2				0x0D
#define NGL_MAT3				0x0E
#define NGL_MAT4				0x0F
#define NGL_SAMPLER_2D			0x10
#define NGL_SAMPLER_CUBE		0x11

// Size of basic data types
#define NGL_SIZE_DOUBLE			8
#define NGL_SIZE_LONG_LONG		8
#define NGL_SIZE_ULONG_LONG		8
#define NGL_SIZE_POINTER		4
#define NGL_SIZE_FLOAT			4
#define NGL_SIZE_LONG			4
#define NGL_SIZE_ULONG			4
#define NGL_SIZE_INT			4
#define NGL_SIZE_UINT			4
#define NGL_SIZE_SHORT			2
#define NGL_SIZE_USHORT			2
#define NGL_SIZE_CHAR			1
#define NGL_SIZE_UCHAR			1
#define NGL_SIZE_BOOL			1
#define NGL_SIZE_VEC2			8
#define NGL_SIZE_VEC3			12
#define NGL_SIZE_VEC4			16
#define NGL_SIZE_IVEC2			8
#define NGL_SIZE_IVEC3			12
#define NGL_SIZE_IVEC4			16
#define NGL_SIZE_BVEC2			2
#define NGL_SIZE_BVEC3			3
#define NGL_SIZE_BVEC4			4
#define NGL_SIZE_MAT2			16
#define NGL_SIZE_MAT3			36
#define NGL_SIZE_MAT4			64
#define NGL_SIZE_BOX			96

// Max data number.
#define NGL_MAX_8				255
#define NGL_MAX_16				65535
#define NGL_MAX_32				4294967295u
#define NGL_MAX_64				18446744073709551615ull

// Time.
#define NGL_NSEC				1000000000ull
#define NGL_USEC				1000000ull
#define NGL_MAX_FPS				60.0f
#define NGL_CYCLE				1.0f / NGL_MAX_FPS
#define NGL_CYCLE_USEC			NGL_CYCLE * NGL_USEC
#define NGL_CYCLE_NSEC			NGL_CYCLE * NGL_NSEC
#define NGL_TIME_RESIZE			0.3f

// Invalid datas.
#define NGL_BLANK_CHAR			' '
#define NGL_NOT_FOUND			NGL_MAX_32

// OS Versions

// This iOS version is necessary to use:
//	- GCD
//	- Blocks
//	- NSRegularExpression
#define NGL_IOS_4_0				4.0f
#define NGL_IOS_4_1				4.1f
#define NGL_IOS_4_2				4.2f
#define NGL_IOS_4_3				4.3f

// This iOS version is necessary to use:
//	- 32 bits data type in shaders
#define NGL_IOS_5_0				5.0f
#define NGL_IOS_5_1				5.1f

#pragma mark -
#pragma mark Functions Definitions
#pragma mark -
//**********************************************************************************************************
//
//	Functions Definitions
//
//**********************************************************************************************************

/*!
 *					This is a simple function that outputs to the console panel three information:
 *
 *                      - The current Thread;
 *                      - The current Selector;
 *                      - The current Class.
 */
#define nglLog()				NSLog(@"%@ :: %s", [NSThread currentThread], __PRETTY_FUNCTION__)

/*!
 *					Releases a C memory pointer.
 *
 *					Prevents NULL pointers or non-allocated values of being freed (zombies).
 *
 *	@param			x
 *					Any C pointer.
 */
#define nglFree(x)				({ if(x) { free(x); (x) = NULL; } })

/*!
 *					Releases an Objective-C instance.
 *
 *					Prevents nil pointers or non-allocated objects of being released (zombies).
 *
 *	@param			x
 *					Any Obj-C object.
 */
#ifdef NGL_ARC
	#define nglRelease(x)		({ (x) = nil; })
#else
	#define nglRelease(x)		({ if(x) { [x release]; (x) = nil; } })
#endif

/*!
 *					Autoreleases an Objective-C instance.
 *
 *	@param			x
 *					Any Obj-C object.
 */
#ifdef NGL_ARC
	#define nglAutorelease(x)	(x)
#else
	#define nglAutorelease(x)	([x autorelease])
#endif

/*!
 *					Retains an Objective-C instance.
 *
 *	@param			x
 *					Any Obj-C object.
 */
#ifdef NGL_ARC
	#define nglRetain(x)		(x)
#else
	#define nglRetain(x)		([x retain])
#endif

/*!
 *					Generate a static single point of access to a Obj-C object. Calling the function
 *					will always return an initialized object.
 */
#define NGL_STATIC_GET_FUNCTION(functionName, class) \
static class *functionName(void) \
{ \
	static class *_default = nil; \
	\
	static dispatch_once_t onceToken; \
	dispatch_once(&onceToken, ^(void) \
	{ \
		_default = [[class alloc] init]; \
	}); \
	\
	return _default; \
}

/*!
 *					Safe way to call a block, avoiding nil or invalid instance. This function doesn't
 *					make a copy of the block, it just executes it safely.
 */
#define nglBlock(block, ...)	({ if ((block) != nil) { (block)(__VA_ARGS__); } })

/*!
 *					This is a simple function that returns the current absolute time of the system.
 *					It is given in seconds (32 bits float data type) and its related to the number of
 *					clock cycles since the start of the system.
 */
#define nglAbsoluteTime()		((float)CACurrentMediaTime())

/*!
 *					Avoid processing the code after this more than once.
 *
 *					...
 *					kmOnceToken();
 *					// The following lines will happen once.
 *					...
 */
#define nglOnceToken()			({ static BOOL _once = NO; if (_once) { return; } _once = YES; })
