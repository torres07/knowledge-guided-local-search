#pragma once

class Vertex {
	public:
		int id;
		float demand, cost;
		int x, y;

		bool operator == (const Vertex& v) const { return x == v.x && y == v.y && id == v.id; }
		Vertex(int id, int x, int y, float demand);
		Vertex();
};