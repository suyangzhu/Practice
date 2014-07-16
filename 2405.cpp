#include <iostream>
#include <cstdio>
#include <cstdlib>

bool search (Graph g, Node start, Node end) {
  Queue q = new Queue;
  for each Node in Graph g
    state[n] = NOT_VISITED;
  state[start] = VISITING;
  q.enqueue(start);

  while(!q.empty()) {
    n = q.dequeue;
    for each v in n.adjacent_vertices{
      if state[v] = NOT_VISITED {
        if (v == end) 
          return true;
        else {
          state[v] = VISITING;
          q.enqueue(v);
          }
      }
    }
    state[n] = VISITED;
  }
  return false;
}

bool search(Graph g, Node start, Node end) {
  Stack q = new Stack;
  for each Node in Graph
    state [n] = NOT_VISITED;
  q.push (start);
  state[start] = VISITING;
  while(!q.empty) {
    n = q.pop();
    for each v in n.adjacent_vertices{
      if state[v] == NOT_VISITED {
        if (v==end)
          return true;
        else {
          state[v] = VISITING;
          q.push(v) ;
        }
      }
    }
  }
  state[n] = VISITED;
}
