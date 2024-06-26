/*
 * libc/stdlib/qsort.c
 *
 * Copyright (C) 2015-2018 BeiJing OURS Education Technology Co., Ltd.
 * Copyright (C) 2017 Tangle.Xu. All rights reserved.
 *
 * Official site: http://www.ourselec.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can access it online at
 * http://www.gnu.org/licenses/gpl-2.0.html.
 *
 * Author: Tangle.Xu <420724072@qq.com>
 * Date: 2017.05
 * Version: v0.1
 *
 */

#include <stdlib.h>

#ifndef MIN
#define MIN(a, b)	((a) < (b) ? (a) : (b))
#endif

#define swapcode(TYPE, parmi, parmj, n) {	\
	long i = (n) / sizeof (TYPE);			\
	TYPE *pi = (TYPE *) (parmi);			\
	TYPE *pj = (TYPE *) (parmj);			\
	do {									\
		TYPE	t = *pi;					\
		*pi++ = *pj;						\
		*pj++ = t;							\
        } while (--i > 0);					\
}

#define swap(a, b)							\
	if (swaptype == 0) {					\
		long t = *(long *)(a);				\
		*(long *)(a) = *(long *)(b);		\
		*(long *)(b) = t;					\
	} else									\
		swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n)					\
	if ((n) > 0)							\
		swapfunc(a, b, n, swaptype)

#define SWAPINIT(a, es)						\
	swaptype = ((char *)a - (char *)0) % sizeof(long) || es % sizeof(long) ? 2 : es == sizeof(long)? 0 : 1;

static __inline char * med3(char *a, char *b, char *c, int (*cmp)(const void *, const void *))
{
	return cmp(a, b) < 0 ?
			(cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a)) :
			(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c));
}

static __inline void swapfunc(char *a, char *b, int n, int swaptype)
{
	if (swaptype <= 1)
		swapcode(long, a, b, n)
	else
		swapcode(char, a, b, n)
}

void qsort(void * aa, size_t n, size_t es, int (*cmp)(const void *, const void *))
{
	char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
	int d, r, swaptype, swap_cnt;
	char *a = aa;

loop: SWAPINIT(a, es);
	swap_cnt = 0;
	if (n < 7)
	{
		for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
			for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0; pl -= es)
				swap(pl, pl - es);
		return;
	}
	pm = (char *) a + (n / 2) * es;
	if (n > 7)
	{
		pl = (char *) a;
		pn = (char *) a + (n - 1) * es;
		if (n > 40)
		{
			d = (n / 8) * es;
			pl = med3(pl, pl + d, pl + 2 * d, cmp);
			pm = med3(pm - d, pm, pm + d, cmp);
			pn = med3(pn - 2 * d, pn - d, pn, cmp);
		}
		pm = med3(pl, pm, pn, cmp);
	}
	swap(a, pm);
	pa = pb = (char *) a + es;

	pc = pd = (char *) a + (n - 1) * es;
	for (;;)
	{
		while (pb <= pc && (r = cmp(pb, a)) <= 0)
		{
			if (r == 0)
			{
				swap_cnt = 1;
				swap(pa, pb);
				pa += es;
			}
			pb += es;
		}
		while (pb <= pc && (r = cmp(pc, a)) >= 0)
		{
			if (r == 0)
			{
				swap_cnt = 1;
				swap(pc, pd);
				pd -= es;
			}
			pc -= es;
		}
		if (pb > pc)
			break;
		swap(pb, pc);
		swap_cnt = 1;
		pb += es;
		pc -= es;
	}
	if (swap_cnt == 0)
	{
		for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
			for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0; pl -= es)
				swap(pl, pl - es);
		return;
	}

	pn = (char *) a + n * es;
	r = MIN(pa - (char *)a, pb - pa);
	vecswap(a, pb - r, r);
	r = MIN(pd - pc, pn - pd - (int)es);
	vecswap(pb, pn - r, r);
	if ((r = pb - pa) > (int) es)
		qsort(a, r / es, es, cmp);
	if ((r = pd - pc) > (int) es)
	{
		a = pn - r;
		n = r / es;
		goto loop;
	}
}
