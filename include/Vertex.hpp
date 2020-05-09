class Vertex {
	private:
		float demand;
		int coord1, coord2;

	public:
		Vertex(int coord1, int coord2, float demand);
		
		void setCoord1(int coord1);
		int getCoord1();

		void setCoord2(int coord2);
		int getCoord2();
		
		void setDemand(float demand);
		float getDemand();
};