class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }

        boolean[] vis = new boolean[n];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            Queue<Integer> queue = new LinkedList<>();
            queue.offer(i);
            vis[i] = true;

            int nodes = 0;      // Number of nodes in the component
            int edgeCount = 0;  // Sum of degrees in the component

            while (!queue.isEmpty()) {
                int u = queue.poll();

                nodes++;
                edgeCount += adj[u].size();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        queue.offer(v);
                    }
                }
            }

            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2) {
                ans++;
            }
        }

        return ans;
    }
}