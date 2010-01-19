/******************************************************************************/
#ifdef JEMALLOC_H_TYPES

#define	UMAX2S_BUFSIZE	65

#ifdef JEMALLOC_STATS
typedef struct tcache_bin_stats_s tcache_bin_stats_t;
typedef struct malloc_bin_stats_s malloc_bin_stats_t;
typedef struct malloc_large_stats_s malloc_large_stats_t;
typedef struct arena_stats_s arena_stats_t;
typedef struct chunk_stats_s chunk_stats_t;
#endif

#endif /* JEMALLOC_H_TYPES */
/******************************************************************************/
#ifdef JEMALLOC_STATS
#ifdef JEMALLOC_H_STRUCTS

#ifdef JEMALLOC_TCACHE
struct tcache_bin_stats_s {
	/*
	 * Number of allocation requests that corresponded to the size of this
	 * bin.
	 */
	uint64_t	nrequests;
};
#endif

struct malloc_bin_stats_s {
	/*
	 * Number of allocation requests that corresponded to the size of this
	 * bin.
	 */
	uint64_t	nrequests;

#ifdef JEMALLOC_TCACHE
	/* Number of tcache fills from this bin. */
	uint64_t	nfills;

	/* Number of tcache flushes to this bin. */
	uint64_t	nflushes;
#endif

	/* Total number of runs created for this bin's size class. */
	uint64_t	nruns;

	/*
	 * Total number of runs reused by extracting them from the runs tree for
	 * this bin's size class.
	 */
	uint64_t	reruns;

	/* High-water mark for this bin. */
	size_t		highruns;

	/* Current number of runs in this bin. */
	size_t		curruns;
};

struct malloc_large_stats_s {
	/*
	 * Number of allocation requests that corresponded to this size class.
	 */
	uint64_t	nrequests;

	/* High-water mark for this size class. */
	size_t		highruns;

	/* Current number of runs of this size class. */
	size_t		curruns;
};

struct arena_stats_s {
	/* Number of bytes currently mapped. */
	size_t		mapped;

	/*
	 * Total number of purge sweeps, total number of madvise calls made,
	 * and total pages purged in order to keep dirty unused memory under
	 * control.
	 */
	uint64_t	npurge;
	uint64_t	nmadvise;
	uint64_t	purged;

	/* Per-size-category statistics. */
	size_t		allocated_small;
	uint64_t	nmalloc_small;
	uint64_t	ndalloc_small;

	size_t		allocated_medium;
	uint64_t	nmalloc_medium;
	uint64_t	ndalloc_medium;

	size_t		allocated_large;
	uint64_t	nmalloc_large;
	uint64_t	ndalloc_large;

	/*
	 * One element for each possible size class, including sizes that
	 * overlap with bin size classes.  This is necessary because ipalloc()
	 * sometimes has to use such large objects in order to assure proper
	 * alignment.
	 */
	malloc_large_stats_t	*lstats;
};

struct chunk_stats_s {
	/* Number of chunks that were allocated. */
	uint64_t	nchunks;

	/* High-water mark for number of chunks allocated. */
	unsigned long	highchunks;

	/*
	 * Current number of chunks allocated.  This value isn't maintained for
	 * any other purpose, so keep track of it in order to be able to set
	 * highchunks.
	 */
	unsigned long	curchunks;
};

#endif /* JEMALLOC_H_STRUCTS */
#endif /* JEMALLOC_STATS */
/******************************************************************************/
#ifdef JEMALLOC_H_EXTERNS

extern bool	opt_stats_print;

char	*umax2s(uintmax_t x, unsigned base, char *s);
#ifdef JEMALLOC_STATS
void malloc_cprintf(void (*write4)(void *, const char *, const char *,
    const char *, const char *), void *w4opaque, const char *format, ...)
    JEMALLOC_ATTR(format(printf, 3, 4));
void	malloc_printf(const char *format, ...)
    JEMALLOC_ATTR(format(printf, 1, 2));
#endif

#endif /* JEMALLOC_H_EXTERNS */
/******************************************************************************/
#ifdef JEMALLOC_STATS
#ifdef JEMALLOC_H_INLINES

#endif /* JEMALLOC_H_INLINES */
#endif /* JEMALLOC_STATS */
/******************************************************************************/