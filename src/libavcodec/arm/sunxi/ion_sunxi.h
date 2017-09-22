/*
 * include/linux/ion_sunxi.h
 *
 * Copyright(c) 2013-2015 Allwinnertech Co., Ltd.
 *      http://www.allwinnertech.com
 *
 * Author: liugang <liugang@allwinnertech.com>
 *
 * sunxi ion header file
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __ION_SUNXI_H
#define __ION_SUNXI_H

#define ION_HEAP_TYPE_SUNXI_START (ION_HEAP_TYPE_CUSTOM + 1)
#define ION_HEAP_TYPE_SECURE	  (ION_HEAP_TYPE_SUNXI_START)

typedef struct {
	long 	start;
	long 	end;
}sunxi_cache_range;

typedef struct {
	int handle;
	unsigned int phys_addr;
	unsigned int size;
}sunxi_phys_data;

#define DMA_BUF_MAXCNT 	8

typedef struct {
	unsigned int src_va;
	unsigned int src_pa;
	unsigned int dst_va;
	unsigned int dst_pa;
	unsigned int size;
}dma_buf_item;

typedef struct {
	int multi_dma;
	unsigned int cnt;
	dma_buf_item item[DMA_BUF_MAXCNT];
}dma_buf_group;

#define ION_IOC_SUNXI_FLUSH_RANGE           5
#define ION_IOC_SUNXI_FLUSH_ALL             6
#define ION_IOC_SUNXI_PHYS_ADDR             7
#define ION_IOC_SUNXI_DMA_COPY              8
#define ION_IOC_SUNXI_DUMP                  9

#endif
