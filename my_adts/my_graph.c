#include "my_graph.h"

/*
 * DAG: directed acyclic graph
 * connected undirected graph: path available btw vertexs
 * strongly connected directed graph: path available btw vertexs
 * weekly connected directd graph: not strong connected, but underlying graph is connected.
*/


/*
 * O(V^2)
 * 
*/
void topsort(graph G)
{
	unsigned int counter;
	vertex v, w;
	for (counter = 0; counter < NUM_VERTEX; counter++)
	{
		v = find_new_vertex_of_indegree_zero();
		if (v = NOTE_A_VERTEX)
		{
			//the graph has a cycle
			break;
		}
		top_num[v] = counter;
		for each w adjacent to v 
		{
			indegree[w]--;
		}
	}	
}

/*
 * O(E + V)
*/
void topsort(graph G)
{
	QUEUE Q;
	unsigned int counter;
	vertex v, w;
	Q = create_queue(NUM_VERTEX); make_null(Q); counter = 0;
	for each vertex v
	{
		if (indegree[v] == 0)
		{
			enqueue(v, Q)
		}
	}
	while (!is_empty(Q))
	{
		v = dequeue(Q);
		//we could log v in order to have the top (orderring vertex)
		top_num[v] = ++counter;
		for each w adjacent to v
		{
			if (--indegree[w] == 0)
			{
				enqueue(w, Q);
			}
		}
	}
	if (counter != NUM_VERTEX)
	{
		//the graph has a cycle
	}
	dispose_queue(Q);
}


/*
 * shortest path algorithms
 * unweighted
		O(E + V)
		O(E * LogV)
 * weighted
  		no nagative: 
			O(E + V)
  			O(E * LogV)
		have nagative case
			O(E * V)
		special case of acyclic graphs 
			linear time
*/


/* shortest path
 * breadth-first search
 * O(V^2)
*/
void unweighted(TABLE T)
{
	unsigned int curr_dist;
	vertex v, w;
	for (curr_dist = 0; curr_dist < NUM_VERTEX; curr_dist++)
	{
		for each vertex v
		{
			if (!T[v].known && T[v].dist == curr_dist)
			{
				T[v].known = TRUE;
				for each w adjacent to v
				{
					if (T[w].dist = curr_dist + 1;
					T[w].path = v;					
				}
			}
		}
	}
}

/* shortest path
 * breadth-first search
 * O(V + W)
*/
void unweighted(TABLE T)
{
	QUEUE Q;
	vertex v, w;
	Q = create_queue(NUM_VERTEX); make_null(Q);
	enqueue(s, Q);
	while (!is_empty(Q))
	{
		v = dequeue(Q);
		T[v].known = TRUE;
		for each w adjacent to v
		{
			if (T[w].dist = INT_MAX)
			{
				T[w].dist = T[v].dist + 1;
				T[w].path = v;
				enqueue(w, Q);
			}
		}
	}
	dispose_queue(Q);
}



/* Dijkstra Algorithm
 * solve shortest parth problem of weighted graph
 * Greedy algorithms, in stages by doing what appears to be the best thing at each stage.
 * working as long as no edge has negative cost
*/
typedef int vertex;
typedef int dist_type;
struct table_entry
{
	LIST header;
	int known;
	dist_type dist;
	vertex path;
}
//vertices are numbered from 1
#define NOT_A_VERTEX 0
typedef struct table_entry TABLE[NUM_VERTEX + 1];

void init_table(vertex start, graph G, TABLE T)
{
	int i;
	read_graph(G, T);
	for (i = NUM_VERTEX; i > 0; i--)
	{
		T[i].known = FALSE;
		T[i].dist = INT_MAX;
		T[i].path = NOTE_A_VERTEX;
	}
	T[start].dist = 0;
}

void print_path(vertex v, TABLE T)
{
	if (T[v].path != NOTE_A_VERTEX)
	{
		print_path(T[v].path, T);
		print(" to ");
	}
	print("%v", v);
}

/*
 * O(E + V^2)
 * in case dense graph, E = V^2, it is O(E) linear in the number of edges.
 * in case sparse graph, 
		E = V, it is O(V^2), too slow. 
		improvement method: distances kept int a priority queue: O(E*LogV) 
 * as graphs are typically very sparse, priority queue is popular.
 * if Fibonacci heaps used, O(E + V*LogV) archived. 
*/
void dijkstra(TABLE T)
{
	vertex v, w;
	for (;;)
	{
		/*
		for spare graph, to keep distances in a priority queue 
		delete_min: LogV each, V*LogV totally
		*/
		v = smallest unknown distance vertex;
		if (v == NOT_A_VERTEX) break;
		T[v].known = TRUE;
		for each w adjacent to v
		{
			if (!T[w].known)
			{
				if (T[v].dist + cost(v, w) < T[w].dist)
				{
					/*
					for spare graph, keep distance into priority queue
					option 1: 
						decrease_key: LogV each, E*LogV toltally
						but, find operation not well supported by priority queue, 
							should maintain the location of each vertex in the queue, it is ugly.
					option 2: 
						insert w and the new value of distance(w) into the queue.
						vertex from delete_min should be checked if already known or not
						the size of the queue get to O(E) <= V^2, E*LogV could be archived also.
						but space requirement increased.
						however, E delete_min instead of V delete_min required, likely to be slower in practice.
					*/
					decrease(T[w].dist to T[v].dist + cost(v, w));
					T[w].path = v;
				}
			}
		}
	}
}

/* acyclic graph
 * critical path
 * minimum completion timing
 * earliest completion timing
 * latest completion timing
 * stack timing
 * improve point of Dijkstra: selection rule
 * there is no need for priority queue, 
		select next one (minimum distance) from topo order list, 
		running time is O(E + V) since the selection takes constant timing.
*/



/* minimum spanning tree
 * formed from graph edges that connects all the vertices of G at lowest cost
 * exists if and only if G is connected
 * the number of edge in spanning tree is V - 1, acyclic
 * motivation: wire a house with minimum of cables
 * greedy algorithms
		Prim
		Kruskal
*/


/* Prim algorithms
 * identical to Dijkstra, except the distance(w) updating rule
 * definition of distance(w): the shortest distance for w from known vertexs. 
 * while in Dijkstra, the distance(w) is the shortest for w from the start point.
 * O(V^2) without heap, optimal for dense graphs
 * O(E*LogV) with binary heaps, good for sparse graphs
 * the edges in the spanning tree can be read from the table_entry
 * the total cost is the sum of distance(v)
*/

/* Kruskal algorithms
 * maintain a forest -- a colection of trees
 * initially, V sigle-node trees
 * select and add an edge to merge two trees into one
 * finally, there is only one tree, that is minimum spanning tree.
 * edge to be added should avoid a cycle
 * edge (u, v) selection strategy
	u, v belong to the same set if and only if they are connected in the current spanning forest
	each edge initialized in its own set
	edge sorted in a priority queue
	delete_min, get edge(u, v), O(LogE) for each, O(E*LogE) totally, O(E*LogV) equivalent
		if u, v is not in the same set
			accept edge(u, v)
			union the two sets containing u and v
			all the w adjacent to u or v are now connected, thus belong to the same set.
		else
			reject the edge
		endif
*/
void kruskal(graph G)
{
	unsigned int edges_accepted;
	DISJ_SET S;
	PRIORITY_QUEUE H;
	vertex u, v;
	set_type u_set, v_set;
	edge e;
	initialize(S);
	read_graph_into_heap_array(G, H);
	build_heap(H);
	edges_accepted = 0;
	while (edges_accepted < NUM_VERTEX - 1)
	{
		e = delete_min(H);
		u_set = find(u, S);
		v_set = find(v, S);
		if (u_set != v_set)
		edges_accepted++;
		set_union(S, u_set, v_set);
	}
}


/* Floyd
 * shortestPath(i, j, 0) = w(i, j)
 * shortestPath(i, j, k) = min(
							   shortestPath(i, j, k-1),
							   shortestPath(i, k, k-1) + shortestPath(k, j, k-1)
							  )
 *
*/
{
let dist be a |v|*|v| array of fminimum distances initialized to infinity
let next be a |v|*|v| array of vertex indices initialized to null

procedure FloydWarshallWithPathReconstruction() is
	for each edge(u, v) do
		dist[u][v] = w(u, v)
		next[u][v] = v
	for each vertex v do
		dist[v][v] = 0
		next[v][v] = v
	for k from 1 to |v| do
		for i from 1 to |v|
			for j from 1 to |v|
				if dist[i][j] > dist[i][k] + dist[k][j] then
					dist[i][j] = dist[i][k] + dist[k][j]
					next[i][j] = next[i][k]
					
procedure Path(u, v)
	if next[u][v] = null then
		return []
	while u != v 
		u = next[u][v]
		path.append(u)
	return path;

}


/* Depth-first search
 * preorder
 * O(E) + O(V) (looking for unmarked vertex)
 * start from v1; 
 * dfs v(k)
 * if v(k+1) is unmarked, dfs v(k+1)
*/
void dfs(vertex v)
{
	visited[v] = TRUE:
	for each w adjacent to v
	{
		if (!visited[w])
		{
			dfs(w);
		}
	}
}





