#include <vector>
#include <list>

#include <iostream>

#include "../include/IntraRoute.hpp"

using namespace std;

/**
 * edge<xi,xi.next> = FindMostExpensiveEdge(G)
 * first_node = xi; used_nodes = <xi,xi.next>; cost=0;
 * x = xi; 
 * for k=1 to k_max:
 *     left_nodes = Nodes(G) - used_nodes;
 *     
 *     min(edge<x.next,xl>) for l in left_nodes;
 * 
 *     if( (edge<x.next,xl> - edge<x, x.next>) < 0)
 *         replace(edge<x,x.next>), edge<x.next,xl>)
 *         cost += edge<x.next,xl> - edge<x, x.next>
 *         used_nodes += xl
 *         x = xl
 *     else
 *         break;
 * 
 * replace(edge<x, x.next>, edge<x.next, xi)
 **/      
Route IntraRoute::kopt(Route r, int k) {
    // std::pair<int, Vertex> edge = r.findMostExpensiveEdge();
    std::pair<int, Vertex> edge = r.selectRandomEdge();
    cout << "Random edge selected: " << edge.first << " - " << edge.second.id << endl;

    std::list<Vertex> vertices = r.list();
    int size = vertices.size();

    /** Beginning of the tour **/
    Vertex x_init;
    for(auto v : vertices) {
        if(edge.first == v.id) {
            x_init = v;
            break;
        }
    }
    // Cannot be chosen by algorithm only for closing the tour
    vertices.remove(x_init);

    Vertex x = edge.second; 
    Vertex x_next;
    float spared_cost = 0.0;
    for (size_t i = 0; i < k-1; i++) {
        vertices.remove(x);

        /** Current next vertex of v => <v,v_next> **/
        int x_curr_next = (*r.route[x.id].begin()).id;
        float swap_cost = (-1)*spared_cost;

        /** Find new edge with minimal cost **/
        Vertex x_next;
        bool valid_swap = false;

        for(auto v : vertices) {
            /** Cannot connect back to first node neither to current next node **/
            if(v.id == x_init.id || v.id == x_curr_next || r.route[v.id].empty())
                continue;
            
            // Feasibility test = > Partial Gain Criterion
            bool feasible_swap = false;
            if ((x.cost - r.cost(x, v)) > (-1)*spared_cost) {
                /** Test if adding this edge results in being able to break next edge => Feasibility criterion **/
                for(auto k : vertices) {
                    // This node has already been used
                    Vertex v_next = (*r.route[v.id].begin());
                    Vertex v_next_next = (*r.route[v_next.id].begin());

                    // next vertex from k not equal to init vertex
                    if(v_next.id == x_init.id)
                        continue;

                    // Check if k not equal to next vertex or adjacent to next vertex
                    if(k.id == v_next.id || k.id == v_next_next.id)
                        continue;

                    // Check if k not equal to init vertex or k not equal to vertex being evaluated
                    if(k.id == x_init.id || k.id == v.id)
                        continue;
                    
                    // Check if sum results in gain - Naive Test
                    // cout << "Testing edge:  " << k.id << " - " << v_next.id << endl;
                    if((v_next.cost - r.cost(k, v_next)) > 0) {
                        feasible_swap = true;
                        break;
                    }
                }
            }

            /** Check if current edge should be considered or not **/
            // cout << " Swap Cost for ok edge's: " << (x.cost - r.cost(x, v)) << endl;
            if( feasible_swap && (swap_cost < (x.cost - r.cost(x, v))) ) {
                swap_cost =  x.cost - r.cost(x, v);
                x_next = v;
                valid_swap = true;
            }
        }

        /** If no swap is possible  **/
        if(!valid_swap) {
            break;
        }        

        /** Replace old edge by new edge **/
        spared_cost += swap_cost;

        // /** if spared_cost is negative, stop the algorithm => K-opt is not valid **/
        // if(spared_cost < 0)
        //     throw -1;
        
        x.cost = r.cost(x_next, x);
        std::pair<int, Vertex> new_edge = std::make_pair(x_next.id, x);
        
        cout << "Swaping edges: "<< edge.first << " - " << edge.second.id << " and " << new_edge.first << " - " << new_edge.second.id << endl;
        r.replaceEdge(edge, new_edge);

        /** Update edge and x values **/
        edge = std::make_pair(x_next.id, (*r.route[x_next.id].begin()));
        x = (*r.route[x_next.id].begin());
        vertices.remove(x_next);
        // TODO REMOVE X_PREV FROM X_NEXT FROM LIST TOO, NOT ONLY X_NEXT, OTHERWISE ALGORITHM FAILS.
    }
    
    /** Replace next edge by final edge, reconstructing the tour or assume k-opt has failed **/
    x.cost = r.cost(x_init, x);
    spared_cost += x.cost - edge.second.cost;

    /** Invalid swap in route **/
    if(spared_cost < 0)
        throw -1;
    
    std::pair<int, Vertex>  last_edge = make_pair(x_init.id, x);
    cout << "Swaping edges: "<< edge.first << " - " << edge.second.id << " and " << last_edge.first << " - " << last_edge.second.id << endl;
    r.replaceEdge(edge, last_edge);

    /** Invalid swap in route **/
    if(size != r.list().size())
        throw -2;

    return r;
}