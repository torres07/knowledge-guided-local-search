#pragma once

class Vertex {
	private:
		int id;
		float demand;
		int coord1, coord2;

	public:
		Vertex(int id, int coord1, int coord2, float demand);
		
		void setId(int id);
		int getId();

		void setCoord1(int coord1);
		int getCoord1();

		void setCoord2(int coord2);
		int getCoord2();
		
		void setDemand(float demand);
		float getDemand();
};