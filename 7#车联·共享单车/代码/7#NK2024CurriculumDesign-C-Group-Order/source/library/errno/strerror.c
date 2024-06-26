/*
 * libc/errno/strerror.c
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

#include <errno.h>

/*
 * Returns a string containing a message derived from an error code
 */
char * strerror(int num)
{
	char * p;

	switch(num)
	{
	case ENOERR:
		p = "No error";
		break;

	case EDOM:
		p = "Argument outside domain";
		break;

	case ERANGE:
		p = "Result not representable";
		break;

	case ENOSYS:
		p = "Function not supported";
		break;

	case EINVAL:
		p = "Invalid argument";
		break;

	case ESPIPE:
		p = "Illegal seek";
		break;

	case EBADF:
		p = "Bad file number";
		break;

	case ENOMEM:
		p = "Out of memory";
		break;

	case EACCES:
		p = "Permission denied";
		break;

	case ENFILE:
		p = "File table overflow";
		break;

	case EMFILE:
		p = "Too many open files";
		break;

	case ENAMETOOLONG:
		p = "Filename too long";
		break;

	case ELOOP:
		p = "Too many levels of symbolic links";
		break;

	case ENOMSG:
		p = "No message of desired type";
		break;

	case E2BIG:
		p = "Argument list too long";
		break;

	case EINTR:
		p = "Interrupted system call";
		break;

	case EILSEQ:
		p = "Illegal byte sequence";
		break;

	case ENOEXEC:
		p = "Exec format error";
		break;

	case ENOENT:
		p = "No such file or directory";
		break;

	case EPROTOTYPE:
		p = "Protocol wrong type for socket";
		break;

	case ESRCH:
		p = "No such process";
		break;

	case EPERM:
		p = "Operation not permitted";
		break;

	case ENOTDIR:
		p = "Not a directory";
		break;

	case ESTALE:
		p = "Stale NFS file handle";
		break;

	case EISDIR:
		p = "Is a directory";
		break;

	case EOPNOTSUPP:
		p = "Operation not supported on socket";
		break;

	case ENOTTY:
		p = "Not a tty";
		break;

	case EAGAIN:
		p = "Operation would block";
		break;

	case EIO:
		p = "I/O error";
		break;

	case ENOSPC:
		p = "No space left on device";
		break;

	case EEXIST:
		p = "File exists";
		break;

	case EBUSY:
		p = "Device or resource busy";
		break;

	case EOVERFLOW:
		p = "Value too large for defined data type";
		break;

	default:
		p = "Invalid error number";
		break;
	}

	return p;
}
