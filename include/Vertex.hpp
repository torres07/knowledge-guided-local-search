#pragma once

class Vertex {
	public:
		int id;
		float demand;
		int x, y;
		Vertex(int id, int x, int y, float demand);
};