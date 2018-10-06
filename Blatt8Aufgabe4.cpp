#include <iostream>
#include <stack>
#include <vector>

int main()
{
	size_t n;
	if (not (std::cin >> n)) {
		std::cerr << "Error: Couldn't read n.";
		return 1;
	}
	
	std::vector<std::vector<size_t>> comefrom(n);
	for (size_t x, y; std::cin >> x >> y; comefrom[y].push_back(x));
	
	
	// save path in prev
	std::vector<size_t> prev(n);
	
	// look for a path from 1 to 0
	std::stack<size_t> unexplored;
	std::vector<bool> visited(n, false);
	
	unexplored.push(1);
	visited[1] = true;
	
	while(not unexplored.empty()) {
		size_t current = unexplored.top();
		unexplored.pop();
		for (auto next : comefrom[current]) {
			if (not visited[next]) {
				visited[next] = true;
				unexplored.push(next);
				prev[next] = current;
			}
		}
	}
	
	if (not visited[0]) {
		std::cout << "Es gibt keine solche Folge.\n";
	} else {
		// Now, prev saves the 1-0-path, backwards.
		for (size_t current = 0; current != 1; current = prev[current]) {
			std::cout << current << " ";
		}
		std::cout << 1 << std::endl;
	}
	
	return 0;
}
