/*
 *  CoreVideo.h
 *  CoreVideo
 *
 *  Copyright (c) 2004 Apple Computer, Inc. All rights reserved.
 *
 */
/*!
    @header CoreVideo
        @copyright 2004 Apple Computer, Inc. All rights reserved.
        @availability Mac OS X 10.4 or later
    @abstract   Umbrella header for the CoreVideo framework
    @discussion This header includes all necesssary headers for the CoreVideo
   API
*/

#include <AvailabilityMacros.h>
#include <TargetConditionals.h>

#if TARGET_OS_MAC
#include <QuartzCore/CVBase.h>
#include <QuartzCore/CVBuffer.h>
#include <QuartzCore/CVDisplayLink.h>
#include <QuartzCore/CVHostTime.h>
#include <QuartzCore/CVOpenGLBuffer.h>
#include <QuartzCore/CVOpenGLBufferPool.h>
#include <QuartzCore/CVOpenGLTexture.h>
#include <QuartzCore/CVOpenGLTextureCache.h>
#include <QuartzCore/CVPixelBuffer.h>
#include <QuartzCore/CVPixelBufferPool.h>
#include <QuartzCore/CVPixelFormatDescription.h>
#include <QuartzCore/CVReturn.h>
#else
#include <CVBase.h>
#include <CVBuffer.h>
#include <CVDirect3DBuffer.h>
#include <CVDirect3DBufferPool.h>
#include <CVDirect3DTexture.h>
#include <CVDirect3DTextureCache.h>
#include <CVHostTime.h>
#include <CVPixelBuffer.h>
#include <CVPixelBufferPool.h>
#include <CVPixelFormatDescription.h>
#include <CVReturn.h>
#endif
