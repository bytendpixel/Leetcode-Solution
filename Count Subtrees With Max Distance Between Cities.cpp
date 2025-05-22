class Solution {
public:
    uint8_t distance[16][16] = {};
    uint16_t children[16] = {};
    uint16_t path[16][16] = {};
    uint16_t nodes; 

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        nodes = n;
        // compute all children between nodes
        for(const auto& edge: edges) {
            children[edge[0] - 1] |= 1 << (edge[1] - 1);
            children[edge[1] - 1] |= 1 << (edge[0] - 1);
        }
        // compute all pairwise distances between nodes
        for(uint16_t i = 0; i < nodes; i++) {
            process(i, i); 
        }
        vector<int> output(nodes - 1, 0);
        search(0, 0, output);
        return output;
    }
    void process(uint16_t node, uint16_t origin, uint16_t parent = 0, uint8_t d = 0, uint16_t visited = 0) {
        uint16_t bits = children[node];
        while(bits > 0) {
            uint16_t bit = bits & (-bits);
            if(bit != parent) {
                uint16_t child = __builtin_ctz(bit);
                distance[origin][child] = d + 1;
                path[origin][child] = visited;
                process(child, origin, 1 << node, d + 1, visited | bit);
            } 
            bits ^= bit;
        }
    }
    void search(uint16_t taken, uint16_t necessary, vector<int>& output, uint8_t index = 0, uint8_t diameter = 0) {
        if(index == nodes) {
            if(diameter > 0 && (taken & necessary) == necessary) {
                output[diameter - 1]++;
            }
            return;
        }
        // leave
        search(taken, necessary, output, index + 1, diameter);
        // take
        uint16_t bits = taken;
        while(bits > 0) {
            uint16_t bit = bits & (-bits); 
            uint8_t code = __builtin_ctz(bit);
            diameter = max(diameter, distance[index][code]);
            necessary |= path[index][code]; 
            bits ^= bit;
        }
        taken ^= (1 << index);
        search(taken, necessary, output, index + 1, diameter);
    }
};
