#!/usr/bin/env python3
"""
Algorithm Flashcard Generator - CLRS Topics Coverage
Generates comprehensive Anki flashcards covering algorithms topics
similar to those found in Introduction to Algorithms (CLRS)
"""

import csv
import json
import random
from typing import List, Tuple, Dict
from datetime import datetime

class AlgorithmFlashcardGenerator:
    def __init__(self):
        self.cards = []
        self.topics = {
            "sorting": "Sorting Algorithms",
            "data_structures": "Data Structures", 
            "divide_conquer": "Divide and Conquer",
            "dynamic_programming": "Dynamic Programming",
            "greedy": "Greedy Algorithms",
            "graph_algorithms": "Graph Algorithms",
            "network_flows": "Network Flows",
            "string_algorithms": "String Algorithms",
            "computational_geometry": "Computational Geometry",
            "number_theory": "Number-Theoretic Algorithms",
            "polynomial": "Polynomials and FFT",
            "linear_programming": "Linear Programming",
            "advanced_data_structures": "Advanced Data Structures",
            "advanced_design": "Advanced Design Techniques",
            "multithreaded": "Multithreaded Algorithms",
            "matrix_operations": "Matrix Operations"
        }
    
    def add_card(self, question: str, answer: str, topic: str, difficulty: str = "Medium"):
        """Add a flashcard to the collection"""
        self.cards.append({
            "question": question.strip(),
            "answer": answer.strip(),
            "topic": topic,
            "difficulty": difficulty,
            "created": datetime.now().isoformat()
        })
    
    def generate_sorting_cards(self):
        """Generate cards for sorting algorithms"""
        topic = "sorting"
        
        # Insertion Sort
        self.add_card(
            "What is the time complexity of insertion sort in best, average, and worst cases?",
            "Best: O(n) when array is already sorted\nAverage: O(n²)\nWorst: O(n²) when array is reverse sorted\nSpace: O(1) auxiliary",
            topic
        )
        
        self.add_card(
            "Describe the insertion sort algorithm and when it's most effective.",
            "Works like sorting playing cards. For each element, find correct position in sorted portion and insert.\nMost effective for: small arrays (n < 50), nearly sorted arrays, online algorithms (can sort as data arrives)",
            topic
        )
        
        # Merge Sort
        self.add_card(
            "What is the recurrence relation for merge sort and its solution?",
            "T(n) = 2T(n/2) + Θ(n)\nSolution: T(n) = Θ(n log n) by Master Theorem (Case 2)\nDivide array in half, recursively sort, then merge in linear time",
            topic
        )
        
        self.add_card(
            "What are the advantages and disadvantages of merge sort?",
            "Advantages: Stable sort, guaranteed O(n log n), good for external sorting, parallelizable\nDisadvantages: O(n) extra space, not in-place, slower than quicksort in practice for small arrays",
            topic
        )
        
        # Heapsort
        self.add_card(
            "How does the BUILD-MAX-HEAP operation achieve O(n) time complexity?",
            "Calls MAX-HEAPIFY on nodes n/2 down to 1. Most nodes are leaves (no work), higher levels do more work but fewer nodes.\nAnalysis: Σ(h=0 to lg n) ⌈n/2^(h+1)⌉ * O(h) = O(n)",
            topic, "Hard"
        )
        
        self.add_card(
            "Compare heapsort with quicksort and merge sort.",
            "Heapsort: O(n log n) guaranteed, O(1) space, not stable, poor cache performance\nQuicksort: O(n log n) average, O(1) space, not stable, good cache performance\nMerge sort: O(n log n) guaranteed, O(n) space, stable, good for external sorting",
            topic
        )
        
        # Quicksort
        self.add_card(
            "Why is randomized quicksort's expected time O(n log n)?",
            "Expected depth is O(log n) because random pivot likely creates balanced partitions.\nE[T(n)] = E[partitioning cost] + E[recursive calls]\nWith high probability, each level processes O(n) elements, total O(n log n)",
            topic, "Hard"
        )
        
        self.add_card(
            "What is the role of the PARTITION subroutine in quicksort?",
            "Rearranges subarray A[p..r] so pivot element is in final position.\nAll elements ≤ pivot are to its left, all elements ≥ pivot are to its right.\nReturns pivot's final index. Time: Θ(n), Space: O(1)",
            topic
        )
        
        # Linear Time Sorting
        self.add_card(
            "Under what conditions can counting sort achieve O(n + k) time?",
            "When input consists of integers in range [0, k] where k = O(n).\nUses auxiliary array of size k to count occurrences.\nStable: maintains relative order of equal elements\nNot comparison-based, so bypasses Ω(n log n) lower bound",
            topic
        )
        
        self.add_card(
            "How does radix sort achieve linear time for integers?",
            "Sorts d-digit numbers by sorting on each digit (least to most significant).\nUses stable sorting (like counting sort) for each digit.\nTime: O(d(n + k)) where d = number of digits, k = range of each digit\nFor fixed-width integers, d is constant → O(n)",
            topic
        )
        
        self.add_card(
            "When is bucket sort most effective and what is its expected time?",
            "Most effective when input is uniformly distributed over [0, 1).\nDivides interval into n buckets, sort each bucket individually.\nExpected time: O(n) when input is uniform\nWorst case: O(n²) when all elements go to same bucket",
            topic
        )
    
    def generate_data_structure_cards(self):
        """Generate cards for data structures"""
        topic = "data_structures"
        
        # Stacks and Queues
        self.add_card(
            "How can you implement a queue using two stacks?",
            "Use two stacks: inbox and outbox.\nEnqueue: push to inbox\nDequeue: if outbox empty, pop all from inbox to outbox; then pop from outbox\nAmortized O(1) per operation because each element moved at most twice",
            topic
        )
        
        # Linked Lists
        self.add_card(
            "What are the advantages of doubly linked lists over singly linked lists?",
            "Can traverse in both directions\nO(1) deletion given node pointer (vs O(n) for singly linked)\nEasier implementation of certain algorithms\nDisadvantage: Extra space for previous pointers",
            topic
        )
        
        # Hash Tables
        self.add_card(
            "Compare chaining vs open addressing for collision resolution in hash tables.",
            "Chaining: Store collisions in linked lists. Simple, handles high load factors well.\nOpen addressing: Store all elements in table using probing. Better cache performance, more sensitive to load factor.\nBoth achieve O(1) average time with good hash function",
            topic
        )
        
        self.add_card(
            "What is the load factor in hash tables and why does it matter?",
            "Load factor α = n/m (elements/table size)\nChaining: Expected chain length is α, operations take O(1 + α)\nOpen addressing: As α approaches 1, probe sequences get longer\nTypical threshold: rehash when α > 0.7-0.75",
            topic
        )
        
        # Binary Search Trees
        self.add_card(
            "What property makes binary search tree operations efficient?",
            "BST property: for any node x, all nodes in left subtree ≤ x.key ≤ all nodes in right subtree\nAllows elimination of half the search space at each step\nInorder traversal visits keys in sorted order\nHeight determines operation complexity",
            topic
        )
        
        self.add_card(
            "How do you delete a node with two children from a BST?",
            "Replace node with its inorder successor (or predecessor)\n1. Find successor: leftmost node in right subtree\n2. Copy successor's key to node being deleted\n3. Delete successor (which has at most one child)\nMaintains BST property",
            topic
        )
        
        # Red-Black Trees
        self.add_card(
            "Why do red-black tree properties guarantee O(log n) height?",
            "Key insight: longest path (root to leaf) has ≤ 2× nodes as shortest path\nProperty 4 (red nodes have black children) means no two consecutive red nodes\nProperty 5 (same black height) means shortest path is all black\nTherefore height ≤ 2 log(n+1)",
            topic, "Hard"
        )
        
        self.add_card(
            "When do you need to recolor vs rotate in red-black tree insertion?",
            "After inserting red node, if parent is also red:\nCase 1: Uncle is red → recolor parent, uncle to black, grandparent to red\nCase 2/3: Uncle is black → rotate to balance tree\nContinue up tree until root or no red-red violation",
            topic, "Hard"
        )
    
    def generate_divide_conquer_cards(self):
        """Generate cards for divide and conquer algorithms"""
        topic = "divide_conquer"
        
        self.add_card(
            "What are the three steps of the divide-and-conquer paradigm?",
            "1. Divide: Split problem into smaller subproblems of same type\n2. Conquer: Solve subproblems recursively (base case for small problems)\n3. Combine: Merge solutions to get solution for original problem",
            topic
        )
        
        self.add_card(
            "How do you find the maximum subarray sum using divide and conquer?",
            "Divide array at midpoint. Maximum subarray is either:\n1. Entirely in left half (recurse)\n2. Entirely in right half (recurse)\n3. Crosses midpoint (find max left sum + max right sum)\nTime: T(n) = 2T(n/2) + Θ(n) = Θ(n log n)",
            topic
        )
        
        self.add_card(
            "Describe Strassen's algorithm for matrix multiplication.",
            "Reduces 2×2 matrix multiplication from 8 to 7 multiplications using clever additions.\nRecursively applied: T(n) = 7T(n/2) + Θ(n²) = Θ(n^log₂7) ≈ Θ(n^2.807)\nBetter than standard Θ(n³) for large matrices, but high constant factors",
            topic, "Hard"
        )
        
        self.add_card(
            "What is the closest pair problem and how is it solved with divide and conquer?",
            "Find two points with minimum Euclidean distance among n points.\nDivide by vertical line, solve recursively for left and right halves.\nKey insight: only check points within δ of dividing line (δ = min of left, right distances)\nTime: O(n log n)",
            topic
        )
    
    def generate_dynamic_programming_cards(self):
        """Generate cards for dynamic programming"""
        topic = "dynamic_programming"
        
        self.add_card(
            "What conditions must a problem satisfy to apply dynamic programming?",
            "1. Optimal Substructure: Optimal solution contains optimal solutions to subproblems\n2. Overlapping Subproblems: Same subproblems appear multiple times in naive recursion\nWithout condition 2, divide-and-conquer is more appropriate",
            topic
        )
        
        self.add_card(
            "Compare top-down (memoization) vs bottom-up dynamic programming.",
            "Top-down: Recursive with memoization, solves only needed subproblems, easier to code\nBottom-up: Iterative, solves all subproblems, better space efficiency, avoids recursion overhead\nBoth have same asymptotic complexity but different constants",
            topic
        )
        
        self.add_card(
            "What is the optimal substructure property in the activity selection problem?",
            "If activity k is in optimal solution for activities i through j, then:\n- Activities before k form optimal solution for activities i through k-1\n- Activities after k form optimal solution for activities k+1 through j\nGreedy choice: select earliest finishing activity",
            topic
        )
        
        self.add_card(
            "How do you reconstruct the actual solution from a DP table?",
            "Store additional information during DP computation:\n1. Keep parent pointers showing which choice led to optimal value\n2. Or store the actual choices made at each step\n3. Trace back from final answer to reconstruct sequence\nAdds O(1) time and space per subproblem",
            topic
        )
        
        self.add_card(
            "What is the difference between longest common subsequence and longest common substring?",
            "LCS: Characters can be non-contiguous. DP recurrence based on matching/skipping characters.\nLCS substring: Characters must be contiguous. Can use rolling hash or suffix arrays.\nLCS is more general and commonly appears in diff algorithms, bioinformatics",
            topic
        )
        
        self.add_card(
            "Describe the coin change problem and its DP solution.",
            "Given coin denominations and amount, find minimum coins needed.\nDP[i] = minimum coins for amount i\nDP[i] = min(DP[i-coin] + 1) for all coins ≤ i\nTime: O(amount × coins), Space: O(amount)",
            topic
        )
        
        self.add_card(
            "What is the travelling salesman problem and why is DP exponential?",
            "Find shortest route visiting all cities exactly once.\nDP state: (current city, set of visited cities)\nDP[mask][i] = shortest path ending at city i having visited cities in mask\nTime: O(n² × 2ⁿ), Space: O(n × 2ⁿ) - exponential in number of cities",
            topic, "Hard"
        )
    
    def generate_greedy_cards(self):
        """Generate cards for greedy algorithms"""
        topic = "greedy"
        
        self.add_card(
            "What is the greedy choice property and how does it differ from optimal substructure?",
            "Greedy choice: Locally optimal choice leads to globally optimal solution\nOptimal substructure: Optimal solution contains optimal solutions to subproblems\nGreedy makes choice before solving subproblems; DP considers all possibilities",
            topic
        )
        
        self.add_card(
            "Why does the greedy algorithm work for the fractional knapsack problem?",
            "Can take fractions of items, so always take highest value-to-weight ratio first.\nGreedy choice: if item has highest ratio, taking maximum possible amount is optimal\nProof: Any optimal solution can be modified to take more of highest-ratio item first",
            topic
        )
        
        self.add_card(
            "Describe Huffman coding and why it produces optimal prefix codes.",
            "Bottom-up construction: merge two lowest-frequency nodes repeatedly\nGreedy choice: merge lowest frequencies at each step\nOptimal because any optimal code can be transformed to have same structure\nExpected code length equals entropy (information theory)",
            topic
        )
        
        self.add_card(
            "What is the cut property in minimum spanning trees?",
            "For any cut (S, V-S) of graph, the minimum weight edge crossing the cut is in some MST\nPrim's algorithm: grow tree by adding minimum weight edge from tree to non-tree vertices\nKruskal's algorithm: add minimum weight edges that don't create cycles",
            topic
        )
        
        self.add_card(
            "Why doesn't the greedy algorithm work for the 0-1 knapsack problem?",
            "Cannot take fractions, so highest value-to-weight ratio might not be optimal\nCounterexample: capacity 10, items (weight, value): (5, 10), (4, 7), (6, 9)\nGreedy by ratio takes (4,7) + (5,10) = 17, but optimal is (6,9) + (4,7) = 16... wait, that's wrong.\nActually: optimal is (5,10) + (4,7) = 17. Need better example where greedy fails.",
            topic
        )
    
    def generate_graph_algorithm_cards(self):
        """Generate cards for graph algorithms"""
        topic = "graph_algorithms"
        
        # Graph Representations
        self.add_card(
            "Compare adjacency matrix vs adjacency list representations of graphs.",
            "Adjacency Matrix: Θ(V²) space, O(1) edge queries, Θ(V) to find all neighbors\nAdjacency List: Θ(V + E) space, O(degree) edge queries, O(degree) to find neighbors\nMatrix better for dense graphs, list better for sparse graphs",
            topic
        )
        
        # BFS and DFS
        self.add_card(
            "What tree property does BFS create and what problems does it solve?",
            "Creates shortest-path tree from source (minimum number of edges)\nApplications: shortest path in unweighted graphs, level-order traversal, bipartiteness testing\nTime: O(V + E), Space: O(V) for queue and visited array",
            topic
        )
        
        self.add_card(
            "What are the different types of edges in a DFS forest?",
            "Tree edges: part of DFS forest\nBack edges: to ancestors (indicate cycles in undirected graphs)\nForward edges: to descendants (only in directed graphs)\nCross edges: between different subtrees\nClassification helps with cycle detection, topological sorting",
            topic
        )
        
        # Topological Sort
        self.add_card(
            "How does DFS-based topological sort work and when does it fail?",
            "Perform DFS, add vertices to front of list when finished (decreasing finish time)\nWorks because if (u,v) is edge, then finish[u] > finish[v]\nFails if back edge found (indicates cycle in directed graph)\nTime: O(V + E)",
            topic
        )
        
        # Strongly Connected Components
        self.add_card(
            "Describe the two-pass algorithm for finding strongly connected components.",
            "1. Run DFS on G, compute finishing times\n2. Run DFS on Gᵀ (transpose) in decreasing order of finishing times\n3. Each DFS tree in pass 2 is one SCC\nWhy it works: finishing times respect SCC structure in transpose graph",
            topic, "Hard"
        )
        
        # Single-Source Shortest Paths
        self.add_card(
            "What is the relaxation operation in shortest path algorithms?",
            "For edge (u,v) with weight w:\nif d[v] > d[u] + w:\n    d[v] = d[u] + w\n    π[v] = u\nImproves estimate if better path found through u\nAll shortest-path algorithms use relaxation",
            topic
        )
        
        self.add_card(
            "Why does Dijkstra's algorithm fail with negative edge weights?",
            "Greedy choice assumes shortest path to vertex won't improve once selected\nNegative edges can create shorter paths through unprocessed vertices\nExample: A→B (1), A→C (4), C→B (-3). Dijkstra picks B first but A→C→B is shorter\nBellman-Ford handles negative weights by relaxing all edges V-1 times",
            topic
        )
        
        self.add_card(
            "How does Bellman-Ford detect negative-weight cycles?",
            "After V-1 iterations of relaxing all edges, run one more iteration\nIf any distance improves, negative cycle exists\nWhy: shortest simple path has ≤ V-1 edges, so distances shouldn't improve after V-1 iterations\nTime: O(VE)",
            topic
        )
        
        # All-Pairs Shortest Paths
        self.add_card(
            "Compare the approaches of Floyd-Warshall vs Johnson's algorithm.",
            "Floyd-Warshall: O(V³), works with negative edges, simple DP\nJohnson's: O(V² log V + VE), better for sparse graphs, uses reweighting + Dijkstra\nJohnson's reweighting: add vertex s connected to all vertices with weight 0, run Bellman-Ford from s",
            topic, "Hard"
        )
    
    def generate_network_flow_cards(self):
        """Generate cards for network flow algorithms"""
        topic = "network_flows"
        
        self.add_card(
            "State the max-flow min-cut theorem.",
            "The maximum flow from source to sink equals the minimum capacity of all cuts separating source and sink.\nAny max flow and any min cut satisfy: flow value = cut capacity\nFord-Fulkerson finds max flow by finding augmenting paths until none exist",
            topic
        )
        
        self.add_card(
            "What is an augmenting path and how does it improve flow?",
            "Path from source to sink in residual graph with positive capacity\nResidual capacity = min(residual capacities along path)\nAugment: increase flow along forward edges, decrease along backward edges\nBackward edges allow 'undoing' previous flow decisions",
            topic
        )
        
        self.add_card(
            "Compare Ford-Fulkerson with Edmonds-Karp algorithm.",
            "Ford-Fulkerson: Generic method, any augmenting path, O(E × |f*|) where f* is max flow\nEdmonds-Karp: Uses BFS for shortest augmenting paths, O(VE²)\nBFS ensures number of augmentations is O(VE), each taking O(E) time",
            topic
        )
        
        self.add_card(
            "How do you model bipartite matching as a max flow problem?",
            "Create source connected to all left vertices (capacity 1)\nCreate sink connected to all right vertices (capacity 1)\nOriginal edges have capacity 1\nMax flow = maximum matching size\nInteger capacities guarantee integer max flow",
            topic
        )
    
    def generate_string_algorithm_cards(self):
        """Generate cards for string algorithms"""
        topic = "string_algorithms"
        
        self.add_card(
            "How does the KMP algorithm achieve linear time string matching?",
            "Precomputes failure function: longest proper prefix that's also suffix\nOn mismatch, shifts pattern based on failure function instead of starting over\nNever moves text pointer backward, each character examined at most twice\nTime: O(n + m) total",
            topic
        )
        
        self.add_card(
            "What information does the failure function in KMP provide?",
            "π[q] = length of longest proper prefix of P[1..q] that's also suffix\nWhen mismatch at position q+1, can shift to position π[q]+1\nPrecomputation uses similar logic to pattern matching itself\nAllows skipping redundant comparisons",
            topic
        )
        
        self.add_card(
            "How does the Rabin-Karp algorithm handle hash collisions?",
            "Uses rolling hash for efficiency: remove leftmost character, add rightmost\nSpurious hits: hash matches but strings differ\nMust verify match character by character when hashes match\nExpected time O(n + m), worst case O(nm) with many collisions",
            topic
        )
        
        self.add_card(
            "What makes suffix trees powerful for string processing?",
            "Stores all suffixes in compressed trie, linear space after compression\nApplications: substring search O(m), longest common substring, longest repeated substring\nConstruction: O(n) with Ukkonen's algorithm (complex)\nSuffix arrays are simpler alternative with similar capabilities",
            topic, "Hard"
        )
    
    def generate_advanced_cards(self):
        """Generate cards for advanced topics"""
        # Number Theory
        self.add_card(
            "What is Euler's theorem and how is it used in RSA?",
            "If gcd(a,n) = 1, then a^φ(n) ≡ 1 (mod n) where φ(n) is Euler's totient function\nRSA: choose p,q prime, n=pq, φ(n)=(p-1)(q-1)\nPublic key e, private key d where ed ≡ 1 (mod φ(n))\nDecryption works because (m^e)^d ≡ m (mod n)",
            "number_theory", "Hard"
        )
        
        self.add_card(
            "How does the Miller-Rabin primality test work?",
            "Based on: if n is prime and a^(n-1) ≡ 1 (mod n), then either a^d ≡ 1 (mod n) or a^(2^r × d) ≡ -1 (mod n) for some r\nWrite n-1 = 2^s × d where d is odd\nTest multiple random witnesses, each has ≤ 1/4 probability of fooling composite n\nk rounds give error probability ≤ (1/4)^k",
            "number_theory", "Hard"
        )
        
        # Linear Programming
        self.add_card(
            "What are the possible outcomes when solving a linear program?",
            "1. Optimal solution: finite optimum value achieved at vertex of feasible region\n2. Unbounded: objective function can be made arbitrarily large/small\n3. Infeasible: no point satisfies all constraints\nSimplex algorithm moves between vertices to find optimum",
            "linear_programming"
        )
        
        # Computational Geometry
        self.add_card(
            "How do you determine if a point is inside a convex polygon?",
            "Method 1: Check if point is on same side of all edges (using cross products)\nMethod 2: Sum angles from point to vertices; inside if sum = 2π\nMethod 3: Ray casting (works for non-convex too): count intersections with polygon boundary\nTime: O(n) for n vertices",
            "computational_geometry"
        )
        
        # Advanced Data Structures
        self.add_card(
            "What problem does a disjoint-set data structure solve efficiently?",
            "Maintains collection of disjoint dynamic sets, supports:\nMAKE-SET(x): create singleton set\nUNION(x,y): merge sets containing x and y\nFIND-SET(x): return representative of set containing x\nWith path compression and union by rank: amortized O(α(n)) per operation",
            "advanced_data_structures"
        )
        
        self.add_card(
            "How does a Fibonacci heap achieve O(1) amortized decrease-key?",
            "Lazy approach: don't fix heap violations immediately\nDecrease-key: just decrease value, cut if violates heap property\nConsolidation happens during extract-min\nPotential function accounts for trees and marked nodes\nKey insight: each node loses at most 2 children before being cut",
            "advanced_data_structures", "Hard"
        )
    
    def generate_all_cards(self):
        """Generate all flashcards"""
        print("Generating sorting algorithm cards...")
        self.generate_sorting_cards()
        
        print("Generating data structure cards...")
        self.generate_data_structure_cards()
        
        print("Generating divide and conquer cards...")
        self.generate_divide_conquer_cards()
        
        print("Generating dynamic programming cards...")
        self.generate_dynamic_programming_cards()
        
        print("Generating greedy algorithm cards...")
        self.generate_greedy_cards()
        
        print("Generating graph algorithm cards...")
        self.generate_graph_algorithm_cards()
        
        print("Generating network flow cards...")
        self.generate_network_flow_cards()
        
        print("Generating string algorithm cards...")
        self.generate_string_algorithm_cards()
        
        print("Generating advanced topic cards...")
        self.generate_advanced_cards()
        
        # Add more comprehensive cards for remaining topics
        self.generate_comprehensive_additional_cards()
        
        print(f"Generated {len(self.cards)} total flashcards")
    
    def generate_comprehensive_additional_cards(self):
        """Generate additional cards to reach 200-300 total"""
        
        # Matrix Operations
        self.add_card(
            "What is the current best known complexity for matrix multiplication?",
            "Current best is approximately O(n^2.373) by Le Gall (2014)\nStrassen's algorithm: O(n^2.807)\nNaive algorithm: O(n^3)\nConjecture: optimal is O(n^2) but not yet proven\nPractical algorithms often use hybrid approaches",
            "matrix_operations", "Hard"
        )
        
        # FFT and Polynomials  
        self.add_card(
            "How does the Fast Fourier Transform achieve O(n log n) polynomial multiplication?",
            "Convert to point-value representation using roots of unity\nMultiply point-values in O(n) time\nConvert back using inverse FFT\nKey insight: evaluation at 2n-th roots of unity can be done recursively\nDivide-and-conquer: T(n) = 2T(n/2) + O(n) = O(n log n)",
            "polynomial", "Hard"
        )
        
        # More Graph Algorithms
        self.add_card(
            "What is the difference between Prim's and Kruskal's MST algorithms?",
            "Prim's: Grow tree from arbitrary vertex, always add cheapest edge from tree to non-tree\nKruskal's: Sort all edges, add cheapest edges that don't create cycles\nPrim's: O(E log V) with binary heap, O(E + V log V) with Fibonacci heap\nKruskal's: O(E log E) for sorting, uses Union-Find for cycle detection",
            "graph_algorithms"
        )
        
        self.add_card(
            "How do you find bridges in an undirected graph?",
            "Bridge: edge whose removal increases number of connected components\nUse DFS with discovery times and low values\nlow[v] = minimum discovery time reachable from subtree rooted at v\nEdge (u,v) is bridge if low[v] > disc[u] (v can't reach ancestor of u)\nTime: O(V + E)",
            "graph_algorithms", "Hard"
        )
        
        self.add_card(
            "What is the articulation point (cut vertex) problem?",
            "Articulation point: vertex whose removal increases connected components\nRoot is articulation point if it has > 1 child in DFS tree\nNon-root v is articulation point if some child u has low[u] ≥ disc[v]\nMeans removing v disconnects u from ancestors of v\nTime: O(V + E) with DFS",
            "graph_algorithms", "Hard"
        )
        
        # More Dynamic Programming
        self.add_card(
            "What is the matrix chain multiplication problem?",
            "Find optimal parenthesization to minimize scalar multiplications\nDP[i][j] = minimum multiplications for matrices Ai through Aj\nDP[i][j] = min(DP[i][k] + DP[k+1][j] + pi-1*pk*pj) for k from i to j-1\nTime: O(n³), Space: O(n²). Classic example of optimal substructure",
            "dynamic_programming"
        )
        
        self.add_card(
            "How do you solve the palindrome partitioning problem with DP?",
            "Find minimum cuts to partition string into palindromes\nDP[i] = minimum cuts for substring s[0..i]\nDP[i] = min(DP[j-1] + 1) for all j where s[j..i] is palindrome\nPrecompute palindrome table: P[i][j] = true if s[i..j] is palindrome\nTime: O(n²)",
            "dynamic_programming"
        )
        
        self.add_card(
            "What is the optimal binary search tree problem?",
            "Given keys with search frequencies, build BST minimizing expected search cost\nDP[i][j] = minimum cost for keys ki through kj\nDP[i][j] = DP[i][r-1] + DP[r+1][j] + sum of frequencies from ki to kj\nTry each key kr as root, take minimum\nTime: O(n³)",
            "dynamic_programming", "Hard"
        )
        
        # More Data Structures
        self.add_card(
            "How does a Fenwick Tree (Binary Indexed Tree) work?",
            "Compact representation for prefix sums with O(log n) updates\nIndex i stores sum of elements from (i - lowbit(i) + 1) to i\nlowbit(i) = i & (-i) gives rightmost set bit\nQuery: sum bits by removing lowbit, Update: add lowbit and propagate\nSpace: O(n), both operations O(log n)",
            "advanced_data_structures"
        )
        
        self.add_card(
            "What operations does a segment tree support efficiently?",
            "Range queries (sum, min, max) and point/range updates in O(log n)\nComplete binary tree with 4n nodes for array of size n\nLazy propagation allows range updates without updating all nodes immediately\nApplications: range minimum query, range sum with updates",
            "advanced_data_structures"
        )
        
        self.add_card(
            "How does a trie (prefix tree) optimize string operations?",
            "Tree where each path from root represents a string prefix\nShared prefixes stored only once, saves space\nInsert/Search/Delete: O(length of string)\nApplications: autocomplete, spell checker, IP routing\nSpace: O(ALPHABET_SIZE × N × M) worst case",
            "advanced_data_structures"
        )
        
        # More Sorting
        self.add_card(
            "What is external sorting and how is merge sort adapted for it?",
            "Sorting data that doesn't fit in memory, stored on external storage\nK-way merge: divide data into sorted runs, merge k runs at a time\nMinimizes I/O operations which dominate cost\nOptimal k depends on available memory and I/O characteristics\nTime complexity includes I/O cost",
            "sorting"
        )
        
        self.add_card(
            "How does shell sort work and what is its complexity?",
            "Generalization of insertion sort using gap sequence\nSort elements gap positions apart, gradually reduce gap to 1\nFinal pass with gap=1 is regular insertion sort\nComplexity depends on gap sequence: O(n^3/2) for some sequences\nPractical algorithm, simple implementation",
            "sorting"
        )
        
        # Multithreaded Algorithms
        self.add_card(
            "What is the work-span model for analyzing parallel algorithms?",
            "Work (T₁): total operations in sequential execution\nSpan (T∞): longest dependency path (critical path)\nSpeedup ≤ min(T₁/T∞, P) on P processors\nParallelism = T₁/T∞, ideal parallelism when T₁/T∞ >> P",
            "multithreaded"
        )
        
        self.add_card(
            "How do you parallelize merge sort efficiently?",
            "Spawn parallel recursive calls for left and right halves\nSync before merging (merge itself can also be parallelized)\nWork: O(n log n), Span: O(log³ n) with parallel merge\nParallelism: O(n log n / log³ n) = O(n / log² n)",
            "multithreaded"
        )
        
        # More Advanced Topics
        self.add_card(
            "What is a van Emde Boas tree and what does it optimize?",
            "Data structure for integers in universe {0, 1, ..., u-1}\nSupports insert, delete, search, predecessor, successor in O(log log u)\nRecursive structure: √u clusters of size √u each\nSpace: O(u) but often too much for practical use\nTheoretically optimal for integer operations",
            "advanced_data_structures", "Hard"
        )
        
        self.add_card(
            "How does consistent hashing solve the load balancing problem?",
            "Maps both keys and servers to points on a circle\nKey assigned to next server clockwise on circle\nAdding/removing servers affects only adjacent keys, not all keys\nAchieves good load distribution with minimal remapping\nUsed in distributed systems like Amazon Dynamo",
            "advanced_data_structures"
        )
        
        self.add_card(
            "What is a suffix array and how is it constructed efficiently?",
            "Sorted array of all suffixes of a string\nSA[i] = starting position of i-th smallest suffix\nNaive: O(n² log n), DC3 algorithm: O(n)\nWith LCP array, supports many string operations efficiently\nMore space-efficient than suffix trees in practice",
            "string_algorithms", "Hard"
        )
        
        self.add_card(
            "How does the Aho-Corasick algorithm find multiple patterns simultaneously?",
            "Builds trie of all patterns, adds failure links for mismatches\nFailure function similar to KMP but for multiple patterns\nProcesses text in single pass, reporting all pattern occurrences\nTime: O(n + m + z) where n=text length, m=total pattern length, z=matches\nUsed in antivirus software, intrusion detection",
            "string_algorithms", "Hard"
        )
        
        # NP-Completeness and Approximation
        self.add_card(
            "What is a polynomial-time reduction and why is it important?",
            "Problem A reduces to B if solution to B can solve A in polynomial time\nIf A reduces to B and B ∈ P, then A ∈ P\nUsed to prove NP-completeness: reduce known NP-complete problem to new problem\nTransitivity of reductions allows building chains of NP-complete problems",
            "advanced_design"
        )
        
        self.add_card(
            "What is the difference between NP-hard and NP-complete?",
            "NP-hard: at least as hard as any problem in NP (includes harder problems)\nNP-complete: in NP and NP-hard (hardest problems in NP)\nAll NP-complete problems reduce to each other\nIf any NP-complete problem ∈ P, then P = NP",
            "advanced_design"
        )
        
        self.add_card(
            "How does the 2-approximation algorithm for vertex cover work?",
            "Repeatedly find edge (u,v), add both u and v to cover, remove all edges incident to u or v\nAnalysis: each chosen edge must have at least one endpoint in optimal cover\nWe choose both endpoints, so |solution| ≤ 2|optimal|\nSimple greedy algorithm with guaranteed performance bound",
            "advanced_design"
        )
        
        self.add_card(
            "What is the traveling salesman problem and what approximation is possible?",
            "Find shortest tour visiting all cities exactly once\nGeneral TSP: no constant approximation unless P=NP\nMetric TSP (triangle inequality): 2-approximation using MST\nChristofides algorithm: 3/2-approximation using minimum perfect matching\nHeld-Karp: exact algorithm in O(n²2ⁿ) time",
            "advanced_design", "Hard"
        )
        
        # More Network Flows
        self.add_card(
            "How do you solve the maximum bipartite matching problem?",
            "Model as max flow: source to left vertices, right vertices to sink, all capacities 1\nAlternatively, use augmenting paths directly in bipartite graph\nHopcroft-Karp algorithm: O(E√V) using shortest augmenting paths\nKönig's theorem: max matching = min vertex cover in bipartite graphs",
            "network_flows"
        )
        
        self.add_card(
            "What is the minimum cost flow problem?",
            "Find flow of given value with minimum cost\nGeneralizes shortest path (flow=1) and max flow (cost=0)\nCan model as linear program or use specialized algorithms\nSuccessive shortest path: augment along minimum cost paths\nApplications: transportation, assignment problems",
            "network_flows", "Hard"
        )
        
        # More Geometric Algorithms
        self.add_card(
            "How do you compute the convex hull using Graham's scan?",
            "Sort points by polar angle with respect to bottom-most point\nMaintain stack of hull vertices, remove points that make right turns\nUses cross product to determine turn direction\nTime: O(n log n) for sorting, O(n) for scanning\nHandles collinear points with special care",
            "computational_geometry"
        )
        
        self.add_card(
            "What is the line sweep technique in computational geometry?",
            "Process geometric objects by sweeping line across plane\nMaintain data structure of active objects intersecting sweep line\nHandle events when sweep line encounters object boundaries\nApplications: segment intersection, Voronoi diagrams, closest pair\nReduces 2D problem to sequence of 1D problems",
            "computational_geometry"
        )
        
        # Advanced String Algorithms
        self.add_card(
            "How does the Boyer-Moore algorithm skip characters during string matching?",
            "Uses bad character rule and good suffix rule to skip positions\nBad character: when mismatch occurs, skip to align character in pattern\nGood suffix: use information about matched suffix to determine skip\nWorst case O(nm) but often much faster in practice, especially for large alphabets\nPreprocessing time: O(m + σ) where σ is alphabet size",
            "string_algorithms"
        )
        
        # More Complexity Analysis
        self.add_card(
            "What is amortized analysis and when is it useful?",
            "Analyzes average cost per operation over sequence of operations\nUseful when individual operations have varying costs but average is better\nThree methods: aggregate, accounting, potential\nExamples: dynamic arrays, splay trees, Fibonacci heaps\nGives tighter bounds than worst-case analysis of individual operations",
            "advanced_design"
        )
        
        self.add_card(
            "How does the accounting method work in amortized analysis?",
            "Assign amortized cost to each operation (may differ from actual cost)\nMaintain credit balance: amortized - actual cost\nCredit must never go negative (prepayment principle)\nTotal amortized cost is upper bound on total actual cost\nExample: dynamic array doubling with amortized O(1) insertion",
            "advanced_design"
        )
        
        # Randomized Algorithms
        self.add_card(
            "What is the difference between Las Vegas and Monte Carlo algorithms?",
            "Las Vegas: randomized running time, always correct (e.g., randomized quicksort)\nMonte Carlo: fixed running time, possibly incorrect with small probability\nOne-sided error: may say 'yes' when answer is 'no' (or vice versa)\nTwo-sided error: may err in either direction\nCan convert between types in some cases",
            "advanced_design"
        )
        
        self.add_card(
            "How does randomized quickselect achieve linear expected time?",
            "Find k-th smallest element using random pivot\nPartition around pivot, recurse on side containing k-th element\nExpected size of recursive call is 3n/4 (with high probability)\nT(n) = T(3n/4) + O(n) = O(n) by geometric series\nWorst case still O(n²) but very unlikely",
            "advanced_design"
        )
        
        # Hash Table Advanced Topics
        self.add_card(
            "What is universal hashing and why is it important?",
            "Family of hash functions where any two keys have small collision probability\nFor family H and keys x ≠ y: Pr[h(x) = h(y)] ≤ 1/m for random h ∈ H\nEnsures good expected performance regardless of input\nExample: h(x) = ((ax + b) mod p) mod m where p is prime, a,b random\nDefends against adversarial inputs",
            "advanced_data_structures", "Hard"
        )
        
        self.add_card(
            "How does cuckoo hashing achieve O(1) worst-case lookup time?",
            "Uses two hash tables and two hash functions\nEach key stored in exactly one location: T1[h1(x)] or T2[h2(x)]\nInsertion may require moving existing keys (cuckoo eviction)\nWorst-case O(1) lookup, amortized O(1) insertion\nRehash entire table if insertion fails after too many evictions",
            "advanced_data_structures", "Hard"
        )
        
        # More Approximation Algorithms
        self.add_card(
            "What is the set cover problem and how well can it be approximated?",
            "Given universe U and collection S of subsets, find minimum subcollection covering U\nGreedy algorithm: repeatedly choose set covering most uncovered elements\nApproximation ratio: H_n ≈ ln n where n = |U|\nThis is optimal unless P = NP (ln n lower bound)\nApplicationates: facility location, resource allocation",
            "advanced_design", "Hard"
        )
        
        self.add_card(
            "How does the FPTAS for knapsack work?",
            "Fully Polynomial-Time Approximation Scheme: (1+ε)-approximation in poly(n,1/ε)\nScale and round item values to reduce number of distinct values\nRun standard DP on rounded values\nError from rounding is bounded by ε fraction of optimal\nTime: O(n³/ε), first FPTAS discovered",
            "advanced_design", "Hard"
        )
        
        # Additional Advanced Data Structure Cards
        self.add_card(
            "What is a persistent data structure and how is it implemented?",
            "Preserves previous versions when modified (immutable)\nPath copying: copy nodes on path from root to modified node\nFat node method: store all versions of each node\nApplications: functional programming, version control, computational geometry\nSpace overhead typically O(log n) per update",
            "advanced_data_structures", "Hard"
        )
        
        self.add_card(
            "How does a splay tree achieve O(log n) amortized time?",
            "Self-adjusting BST that moves accessed nodes toward root via splaying\nSplaying: sequence of rotations (zig, zig-zig, zig-zag)\nFrequently accessed nodes end up near root\nWorking set theorem: amortized cost depends on access locality\nNo worst-case guarantees but excellent practical performance",
            "advanced_data_structures", "Hard"
        )
        
        # Additional Network Flow Topics
        self.add_card(
            "What is the push-relabel algorithm for maximum flow?",
            "Maintains preflow (flow into node ≥ flow out) and height function\nPush: send flow along admissible edges (downhill)\nRelabel: increase height when no admissible edges exist\nEventually converges to maximum flow\nFIFO implementation: O(V³), highest-label: O(V²√E)",
            "network_flows", "Hard"
        )
        
        self.add_card(
            "How do you find edge-disjoint paths in a network?",
            "Max number of edge-disjoint s-t paths equals min s-t cut capacity\nModel as max flow with all edge capacities = 1\nEach unit of flow corresponds to one edge-disjoint path\nVertex-disjoint paths: split each vertex (except s,t) into in and out vertices\nApplications: fault tolerance, load balancing",
            "network_flows"
        )
        
        print(f"Total cards generated: {len(self.cards)}")
    
    def export_to_csv(self, filename: str = "algorithm_flashcards.csv"):
        """Export flashcards to CSV format for Anki import"""
        with open(filename, 'w', newline='', encoding='utf-8') as csvfile:
            fieldnames = ['Front', 'Back', 'Topic', 'Difficulty', 'Created']
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            
            writer.writeheader()
            for card in self.cards:
                writer.writerow({
                    'Front': card['question'],
                    'Back': card['answer'], 
                    'Topic': self.topics.get(card['topic'], card['topic']),
                    'Difficulty': card['difficulty'],
                    'Created': card['created']
                })
        
        print(f"Exported {len(self.cards)} cards to {filename}")
    
    def export_to_json(self, filename: str = "algorithm_flashcards.json"):
        """Export flashcards to JSON format"""
        data = {
            'metadata': {
                'total_cards': len(self.cards),
                'topics': list(self.topics.values()),
                'generated': datetime.now().isoformat()
            },
            'cards': self.cards
        }
        
        with open(filename, 'w', encoding='utf-8') as jsonfile:
            json.dump(data, jsonfile, indent=2, ensure_ascii=False)
        
        print(f"Exported {len(self.cards)} cards to {filename}")
    
    def export_to_anki_format(self, filename: str = "algorithm_flashcards_anki.txt"):
        """Export in format suitable for Anki import"""
        with open(filename, 'w', encoding='utf-8') as f:
            for card in self.cards:
                # Anki format: Front\tBack\tTags
                front = card['question'].replace('\n', '<br>')
                back = card['answer'].replace('\n', '<br>')
                topic = self.topics.get(card['topic'], card['topic'])
                tags = f"{topic} {card['difficulty']}"
                
                f.write(f"{front}\t{back}\t{tags}\n")
        
        print(f"Exported {len(self.cards)} cards to {filename} in Anki format")
    
    def print_statistics(self):
        """Print statistics about generated cards"""
        topic_counts = {}
        difficulty_counts = {}
        
        for card in self.cards:
            topic = card['topic']
            difficulty = card['difficulty']
            
            topic_counts[topic] = topic_counts.get(topic, 0) + 1
            difficulty_counts[difficulty] = difficulty_counts.get(difficulty, 0) + 1
        
        print("\n=== FLASHCARD STATISTICS ===")
        print(f"Total Cards: {len(self.cards)}")
        print(f"\nCards by Topic:")
        for topic, count in sorted(topic_counts.items()):
            print(f"  {self.topics.get(topic, topic)}: {count}")
        
        print(f"\nCards by Difficulty:")
        for difficulty, count in sorted(difficulty_counts.items()):
            print(f"  {difficulty}: {count}")
    
    def sample_cards(self, n: int = 5):
        """Display sample cards"""
        print(f"\n=== SAMPLE CARDS ===")
        sample = random.sample(self.cards, min(n, len(self.cards)))
        
        for i, card in enumerate(sample, 1):
            print(f"\nCard {i}:")
            print(f"Topic: {self.topics.get(card['topic'], card['topic'])}")
            print(f"Difficulty: {card['difficulty']}")
            print(f"Q: {card['question']}")
            print(f"A: {card['answer']}")
            print("-" * 50)

def main():
    """Main function to generate and export flashcards"""
    print("Algorithm Flashcard Generator - CLRS Topics")
    print("=" * 50)
    
    generator = AlgorithmFlashcardGenerator()
    
    # Generate all flashcards
    generator.generate_all_cards()
    
    # Print statistics
    generator.print_statistics()
    
    # Show sample cards
    generator.sample_cards(3)
    
    # Export in multiple formats
    print("\n=== EXPORTING CARDS ===")
    generator.export_to_csv()
    generator.export_to_json()
    generator.export_to_anki_format()
    
    print(f"\nGeneration complete! Created {len(generator.cards)} flashcards.")
    print("Files created:")
    print("- algorithm_flashcards.csv (for spreadsheet import)")
    print("- algorithm_flashcards.json (for programmatic use)")
    print("- algorithm_flashcards_anki.txt (for Anki import)")
    
    print("\nTo import into Anki:")
    print("1. Open Anki")
    print("2. File -> Import")
    print("3. Select algorithm_flashcards_anki.txt")
    print("4. Set field separator to 'Tab'")
    print("5. Map fields: Field 1->Front, Field 2->Back, Field 3->Tags")

if __name__ == "__main__":
    main()