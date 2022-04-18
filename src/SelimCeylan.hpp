// SelimCeylan.hpp
#include "INumberSearch.h"


namespace SelimCeylan {
	class NumberSearch : public INumberSearch {
	private:
		int reach;
		std::string x[6];
		std::string y[6];
		int inNumbers[6];
		std::string error = "could not find."; 
		std::string result;
	public:

		// Number to reach (302)
		void SetTargetNumber(const int value) {
			reach = value;

		}
		// Accept numbers as a space separated values : “2 3 7 10 25 50”
		void SetInputNumbers(const std::string& values) {

			//Seperate numbers according to the "space" in string.
			int j = 0;
			for (int i = 0; i < 6; i++) {
				for (j; j < values.length(); j++)
				{	
					if (values[j] == ' ') {
						break;
					}
					x[i] += values[j];
				}
				j++;
			}


			//Convert strings to the integers for calculations.
			inNumbers[0] = std::stoi(x[0]);
			inNumbers[1] = std::stoi(x[1]);
			inNumbers[2] = std::stoi(x[2]);
			inNumbers[3] = std::stoi(x[3]);
			inNumbers[4] = std::stoi(x[4]);
			inNumbers[5] = std::stoi(x[5]);



		}
		// Return result as a string ready to evaluate : “(((2+10)*3)*7)+50)”
		const std::string& GetSolution() {
		//void GetSolution() {
			//Firstly sort the numbers(last index is the biggest).
			int i, j,temp;

			for (i = 0; i < 6; ++i) {
				for (j = i+1; j < 6; ++j)
				{
					if (inNumbers[i] > inNumbers[j]) {
						temp = inNumbers[i];
						inNumbers[i] = inNumbers[j];
						inNumbers[j] = temp;
					}

				}
			}

			//Sort the numbers in string form.
			for(int a=0;a<6;a++)
			x[a] = std::to_string(inNumbers[a]);
			//Try all of the numbers with 2 operation.
			//Multiply every numbers each other.
			int r = 1;
			for (int a = 0; a < 6; a++) {
				r = r * inNumbers[a];
			}
			if (r == reach) {
				result = "(((((" + x[0] + "*" + x[1] + ")" + "*" + x[2] + ")" + "*" + x[3] + ")" + "*" + x[4] + ")" + "*" + x[5] + ")";
				return result;
			}
			//Sum every numbers each other.
			r = 0;
			for (int a = 0; a < 6; a++) {
				r = r + inNumbers[a];
			}
			if (r == reach) {
				result = "(((((" + x[0] + "+" + x[1] + ")" + "+" + x[2] + ")" + "+" + x[3] + ")" + "+" + x[4] + ")" + "+" + x[5] + ")";
				return result;
			}


			//Try to combinations.
			//Try per 2 number (Multiply).
			r = 1;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < 6; b++) {
					if (inNumbers[a] == inNumbers[b]) {
						continue;
					}
					r = inNumbers[a] * inNumbers[b];
					if (r == reach) {
						y[0] = std::to_string(inNumbers[a]);
						y[1] = std::to_string(inNumbers[b]);
						result = "(" + y[0]+"*" + y[1]+ ")";
						return result;
					}
				}
			}
			//Try per 3 number (Multiply).
			r = 1;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < 6; b++) {
					for (int c = 0; c < 6; c++) {
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						if (inNumbers[a] == inNumbers[c]) {
							continue;
						}
						if (inNumbers[b] == inNumbers[c]) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
							continue;
						}
						r = inNumbers[a] * inNumbers[b] * inNumbers[c];
						if (r == reach) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							y[2] = std::to_string(inNumbers[c]);
							result = "((" + y[0] + "*" + y[1] + ")"+"*"+y[2] + ")";
							return result;
							}
					}
				}
			}
			//Try per 4 number (Multiply).
			r = 1;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < 6; b++) {
					for (int c = 0; c < 6; c++) {
						for (int d = 0; d < 6; d++) {

							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[c] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]  == inNumbers[d]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b] * inNumbers[c] * inNumbers[d];
							if (r == reach) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								y[3] = std::to_string(inNumbers[d]);
								result = "(((" + y[0] + "*" + y[1] + ")" + "*" + y[2] + ")" + "*" + y[3] + ")";
								return result;
							}
						}
					}
				}
			}
			//------------------------------------------------------------//
			//Try per 2 number (Sum).
			r = 0;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < 6; b++) {
					if (inNumbers[a] == inNumbers[b]) {
						continue;
					}
					r = inNumbers[a] + inNumbers[b];
					if (r == reach) {
						y[0] = std::to_string(inNumbers[a]);
						y[1] = std::to_string(inNumbers[b]);
						result = "(" + y[0] + "+" + y[1] + ")";
						return result;
					}
				}
			}
			//Try per 3 number (Sum).
			r = 0;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < 6; b++) {
					for (int c = 0; c < 6; c++) {
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						if (inNumbers[a] == inNumbers[c]) {
							continue;
						}
						if (inNumbers[b] == inNumbers[c]) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
							continue;
						}
						r = inNumbers[a] + inNumbers[b] + inNumbers[c];
						if (r == reach) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							y[2] = std::to_string(inNumbers[c]);
							result = "((" + y[0] + "+" + y[1] + ")" + "+" + y[2] + ")";
							return result;
						}
					}
				}
			}
			//Try per 4 number (Sum).
			r = 0;
			for (int a = 0; a < 6; a++) {
				for (int b = 0; b < 6; b++) {
					for (int c = 0; c < 6; c++) {
						for (int d = 0; d < 6; d++) {

							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[c] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b] + inNumbers[c] + inNumbers[d];
							if (r == reach) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								y[3] = std::to_string(inNumbers[d]);
								result =  "(((" + y[0] + "+" + y[1] + ")" + "+" + y[2] + ")" + "+" + y[3] + ")";
								return result;
							}
						}
					}
				}
			}







			//---------------------------------------------------------------------------//
			int op = reach;
			if (reach % inNumbers[5] == 0) {
				op = op / inNumbers[5];
				y[5] = std::to_string(inNumbers[5]);
				result = "(" + y[5] + "*";

				//Try per 2 number (Sum).
				r = 0;
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] + inNumbers[b];
						if (r == op) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "+" + y[1] + ")))";
							return result;
						}
					}
				}
				//Try per 3 number (Sum).
				r = 0;
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						for (int c = 0; c < 5; c++) {
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b] + inNumbers[c];
							if (r == op) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")))";  //Parantezler ve yerleri.
								return result;
							}
						}
					}
				}
				//Try per 4 number (Sum).
				r = 0;
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						for (int c = 0; c < 5; c++) {
							for (int d = 0; d < 5; d++) {

								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c] + inNumbers[d];
								if (r == op) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									y[3] = std::to_string(inNumbers[d]);
									result += "(" + y[3]  + "+(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
				}
				//---------------------------------------------------------------------//
				if (op % inNumbers[4] == 0) {
					int op1 = op;
					op1 = op1 / inNumbers[4];
					y[4] = std::to_string(inNumbers[4]);
					result += "(" + y[4] + "*";

					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op1) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c];
								if (r == op1) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
					//Try per 4 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								for (int d = 0; d < 5; d++) {
									if (a == 4 || b == 4 || c == 4 || d == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									r = inNumbers[a] + inNumbers[b] + inNumbers[c] + inNumbers[d];
									if (r == op1) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										y[3] = std::to_string(inNumbers[d]);
										result += "(" + y[3] + "+(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + "))))";
										return result;
									}
								}
							}
						}
					}

					if (op1 % inNumbers[3] == 0) {
						int op3 = op1;
						op3 = op3 / inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "*";


						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 5; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] + inNumbers[b] + inNumbers[c];
									if (r == op3) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}
					}

					if (op1 - inNumbers[3] > 0) {
						int op4 = op1;
						op4 = op4 - inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "+";



						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 5; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] * inNumbers[b] * inNumbers[c];
									if (r == op4) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}

					}

					if (op1 % inNumbers[2] == 0) {
						int op5 = op1;
						op5 = op5 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op5) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

					if (op1 - inNumbers[2] > 0) {
						int op6 = op1;
						op6 = op6 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
					}

					r = 0;//(Sum)
					if (op1 % inNumbers[1] == 0) {
						int op7 = op1;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op7) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op - inNumbers[4] > 0) {
					int op2 = op;
					op2 = op2 - inNumbers[4];
					y[4] = std::to_string(inNumbers[4]);
					result += "(" + y[4] + "+";


					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op2) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c];
								if (r == op2) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
					//Try per 4 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								for (int d = 0; d < 5; d++) {
									if (a == 4 || b == 4 || c == 4 || d == 4) {
										continue;
									}

									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									r = inNumbers[a] * inNumbers[b] * inNumbers[c] * inNumbers[d];
									if (r == op2) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										y[3] = std::to_string(inNumbers[d]);
										result += "(" + y[3] + "*(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + "))))";
										return result;
									}
								}
							}
						}
					}



					if (op2 % inNumbers[3] == 0) {
						int op3 = op2;
						op3 = op3 / inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "*";


						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 6; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] + inNumbers[b] + inNumbers[c];
									if (r == op3) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}
					}

					if (op2 - inNumbers[3] > 0) {
						int op4 = op2;
						op4 = op4 - inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "+";



						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 5; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] * inNumbers[b] * inNumbers[c];
									if (r == op4) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}

					}

					if (op2 % inNumbers[2] == 0) {
						int op5 = op2;
						op5 = op5 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op5) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

					if (op2 - inNumbers[2] > 0) {
						int op6 = op2;
						op6 = op6 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
					}
					r = 0;//(Sum)
					if (op2 % inNumbers[1] == 0) {
						int op7 = op2;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op7) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}


				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op % inNumbers[3] == 0) {
					int op3 = op;
					op3 = op3 / inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "*";


					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 3 || b == 3) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op3) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 3 || b == 3 || c == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}

					r = 0;//(Sum)
					if (op3 % inNumbers[1] == 0) {
						int op7 = op3;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op7) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op - inNumbers[3] > 0) {
					int op4 = op;
					op4 = op4 - inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "+";



					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 3 || b == 3) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op4) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 3 || b == 3 || c == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}

					r = 0;
					if (op4 % inNumbers[1] == 0) {
						int op8 = op4;
						op8 = op8 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op8) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}


					}
				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op % inNumbers[2] == 0) {
					int op5 = op;
					op5 = op5 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 2 || b == 2) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op5) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					r = 0;
					if (op5 % inNumbers[1] == 0) {
						int op6 = op5;
						op6 = op6 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}
				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op - inNumbers[2] > 0) {
					int op6 = op;
					op6 = op6 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 2 || b == 2) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op6) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}

					r = 0;//(Sum)
					if (op6 % inNumbers[1] == 0) {
						int op7 = op6;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}


				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";


				r = 0;//(Sum)
				if (op % inNumbers[1] == 0) {
					int op7 = op;
					op7 = op7 / inNumbers[1];
					y[1] = std::to_string(inNumbers[1]);
					result += "(" + y[1] + "*";
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op7) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

			}
			result = result.substr(result.length());

			//---------------------------------------------------------------------------//
			op = reach;
			if (reach - inNumbers[5] > 0) {
				op = op - inNumbers[5];
				y[5] = std::to_string(inNumbers[5]);
				result = "(" + y[5] + "+";

				//Try per 2 number (Multiply).
				r = 1;
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] * inNumbers[b];
						if (r == op) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "*" + y[1] + ")))";
							return result;
						}
					}
				}
				//Try per 3 number (Multiply).
				r = 1;
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						for (int c = 0; c < 5; c++) {
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b] * inNumbers[c];
							if (r == op) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")))"; 
								return result;
							}
						}
					}
				}
				//Try per 4 number (Multiply).
				r = 1;
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						for (int c = 0; c < 5; c++) {
							for (int d = 0; d < 5; d++) {

								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c] * inNumbers[d];
								if (r == op) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									y[3] = std::to_string(inNumbers[d]);
									result += "(" + y[3] + "*(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
				}


				if (op % inNumbers[4] == 0) {
					int op1 = op;
					op1 = op1 / inNumbers[4];
					y[4] = std::to_string(inNumbers[4]);
					result += "(" + y[4] + "*";

					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op1) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c];
								if (r == op1) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
					//Try per 4 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								for (int d = 0; d < 5; d++) {
									if (a == 4 || b == 4 || c == 4 || d == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									r = inNumbers[a] + inNumbers[b] + inNumbers[c] + inNumbers[d];
									if (r == op1) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										y[3] = std::to_string(inNumbers[d]);
										result += "(" + y[3] + "+(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + "))))";
										return result;
									}
								}
							}
						}
					}

					if (op1 % inNumbers[3] == 0) {
						int op3 = op1;
						op3 = op3 / inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "*";


						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 5; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] + inNumbers[b] + inNumbers[c];
									if (r == op3) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}
					}

					if (op1 - inNumbers[3] > 0) {
						int op4 = op1;
						op4 = op4 - inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "+";



						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 5; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] * inNumbers[b] * inNumbers[c];
									if (r == op4) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}

					}

					if (op1 % inNumbers[2] == 0) {
						int op5 = op1;
						op5 = op5 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op5) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

					if (op1 - inNumbers[2] > 0) {
						int op6 = op1;
						op6 = op6 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
					}

					r = 0;//(Sum)
					if (op1 % inNumbers[1] == 0) {
						int op7 = op1;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op7) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op - inNumbers[4] > 0) {
					int op2 = op;
					op2 = op2 - inNumbers[4];
					y[4] = std::to_string(inNumbers[4]);
					result += "(" + y[4] + "+";


					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op2) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c];
								if (r == op2) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
					//Try per 4 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								for (int d = 0; d < 5; d++) {
									if (a == 4 || b == 4 || c == 4 || d == 4) {
										continue;
									}

									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
										continue;
									}
									r = inNumbers[a] * inNumbers[b] * inNumbers[c] * inNumbers[d];
									if (r == op2) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										y[3] = std::to_string(inNumbers[d]);
										result += "(" + y[3] + "*(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + "))))";
										return result;
									}
								}
							}
						}
					}



					if (op2 % inNumbers[3] == 0) {
						int op3 = op2;
						op3 = op3 / inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "*";


						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 6; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] + inNumbers[b] + inNumbers[c];
									if (r == op3) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}
					}

					if (op2 - inNumbers[3] > 0) {
						int op4 = op2;
						op4 = op4 - inNumbers[3];
						y[3] = std::to_string(inNumbers[3]);
						result += "(" + y[3] + "+";



						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
						//Try per 3 number (Sum).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								for (int c = 0; c < 5; c++) {
									if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[b] == inNumbers[c]) {
										continue;
									}
									if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
										continue;
									}
									r = inNumbers[a] * inNumbers[b] * inNumbers[c];
									if (r == op4) {
										y[0] = std::to_string(inNumbers[a]);
										y[1] = std::to_string(inNumbers[b]);
										y[2] = std::to_string(inNumbers[c]);
										result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
										return result;
									}
								}
							}
						}

					}

					if (op2 % inNumbers[2] == 0) {
						int op5 = op2;
						op5 = op5 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Sum).
						r = 0;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op5) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

					if (op2 - inNumbers[2] > 0) {
						int op6 = op2;
						op6 = op6 / inNumbers[2];
						y[2] = std::to_string(inNumbers[2]);
						result += "(" + y[2] + "*";

						//Try per 2 number (Multiply).
						r = 1;
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "*" + y[1] + ")))";
									return result;
								}
							}
						}
					}
					r = 0;//(Multiply)
					if (op2 % inNumbers[1] == 0) {
						int op7 = op2;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 4 || b == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op7) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}


				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op % inNumbers[3] == 0) {
					int op3 = op;
					op3 = op3 / inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "*";


					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 3 || b == 3) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op3) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 3 || b == 3 || c == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}

					r = 0;//(Sum)
					if (op3 % inNumbers[1] == 0) {
						int op7 = op3;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op7) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}

				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op - inNumbers[3] > 0) {
					int op4 = op;
					op4 = op4 - inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "+";



					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 3 || b == 3) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op4) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							for (int c = 0; c < 5; c++) {
								if (a == 3 || b == 3 || c == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}

					r = 0;
					if (op4 % inNumbers[1] == 0) {
						int op8 = op4;
						op8 = op8 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 3 || b == 3) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op8) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}


					}
				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op % inNumbers[2] == 0) {
					int op5 = op;
					op5 = op5 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 2 || b == 2) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op5) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					r = 0;
					if (op5 % inNumbers[1] == 0) {
						int op6 = op5;
						op6 = op6 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}
				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				if (op - inNumbers[2] > 0) {
					int op6 = op;
					op6 = op6 - inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "+";

					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (a == 2 || b == 2) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op6) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}

					r = 0;//(Sum)
					if (op6 % inNumbers[1] == 0) {
						int op7 = op6;
						op7 = op7 / inNumbers[1];
						y[1] = std::to_string(inNumbers[1]);
						result += "(" + y[1] + "*";
						for (int a = 0; a < 5; a++) {
							for (int b = 0; b < 5; b++) {
								if (a == 2 || b == 2) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b];
								if (r == op6) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									result += "(" + y[0] + "+" + y[1] + ")))";
									return result;
								}
							}
						}
					}


				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";

				r = 0;//(Sum)
				if (op % inNumbers[1] == 0) {
					int op7 = op;
					op7 = op7 / inNumbers[1];
					y[1] = std::to_string(inNumbers[1]);
					result += "(" + y[1] + "*";
					for (int a = 0; a < 5; a++) {
						for (int b = 0; b < 5; b++) {
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op7) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
				}
				result = result.substr(result.length());
				result = "(" + y[5] + "+";


			}
			result = result.substr(result.length());
			//---------------------------------------------------------------------------//


			op = reach;
			if (op % inNumbers[4] == 0) {
				int op1 = op;
				op1 = op1 / inNumbers[4];
				y[4] = std::to_string(inNumbers[4]);
				result += "(" + y[4] + "*";

				//Try per 2 number (Sum).
				r = 0;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (a == 4 || b == 4) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] + inNumbers[b];
						if (r == op1) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "+" + y[1] + ")))";
							return result;
						}
					}
				}
				//Try per 3 number (Sum).
				r = 0;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						for (int c = 0; c < 6; c++) {
							if (a == 4 || b == 4 || c == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b] + inNumbers[c];
							if (r == op1) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
								return result;
							}
						}
					}
				}
				//Try per 4 number (Sum).
				r = 0;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						for (int c = 0; c < 6; c++) {
							for (int d = 0; d < 6; d++) {
								if (a == 4 || b == 4 || c == 4 || d == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c] + inNumbers[d];
								if (r == op1) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									y[3] = std::to_string(inNumbers[d]);
									result += "(" + y[3] + "+(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + "))))";
									return result;
								}
							}
						}
					}
				}

				if (op1 % inNumbers[3] == 0) {
					int op3 = op1;
					op3 = op3 / inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "*";


					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op3) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 0;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							for (int c = 0; c < 6; c++) {
								if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";

				if (op1 - inNumbers[3] > 0) {
					int op4 = op1;
					op4 = op4 - inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "+";



					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op4) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 1;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							for (int c = 0; c < 6; c++) {
								if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}

				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";

				if (op1 % inNumbers[2] == 0) {
					int op5 = op1;
					op5 = op5 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op5) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";

				if (op1 - inNumbers[2] > 0) {
					int op6 = op1;
					op6 = op6 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op6) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";
			}
			result = result.substr(result.length());
			//---------------------------------------------------------------------------//
			op = reach;
			if (op - inNumbers[4] > 0) {
				int op2 = op;
				op2 = op2 - inNumbers[4];
				y[4] = std::to_string(inNumbers[4]);
				result += "(" + y[4] + "+";


				//Try per 2 number (Multiply).
				r = 1;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (a == 4 || b == 4) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] * inNumbers[b];
						if (r == op2) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "*" + y[1] + ")))";
							return result;
						}
					}
				}
				//Try per 3 number (Multiply).
				r = 1;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						for (int c = 0; c < 6; c++) {
							if (a == 4 || b == 4 || c == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b] * inNumbers[c];
							if (r == op2) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
								return result;
							}
						}
					}
				}
				//Try per 4 number (Multiply).
				r = 1;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						for (int c = 0; c < 6; c++) {
							for (int d = 0; d < 6; d++) {
								if (a == 4 || b == 4 || c == 4 || d == 4) {
									continue;
								}

								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c] == inNumbers[d]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c] * inNumbers[d];
								if (r == op2) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									y[3] = std::to_string(inNumbers[d]);
									result += "(" + y[3] + "*(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + "))))";
									return result;
								}
							}
						}
					}
				}



				if (op2 % inNumbers[3] == 0) {
					int op3 = op2;
					op3 = op3 / inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "*";


					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op3) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 0;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							for (int c = 0; c < 6; c++) {
								if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] + inNumbers[b] + inNumbers[c];
								if (r == op3) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}
				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";
				if (op2 - inNumbers[3] > 0) {
					int op4 = op2;
					op4 = op4 - inNumbers[3];
					y[3] = std::to_string(inNumbers[3]);
					result += "(" + y[3] + "+";



					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op4) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
					//Try per 3 number (Sum).
					r = 1;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							for (int c = 0; c < 6; c++) {
								if (a == 3 || b == 3 || c == 3 || a == 4 || b == 4 || c == 4) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[b] == inNumbers[c]) {
									continue;
								}
								if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
									continue;
								}
								r = inNumbers[a] * inNumbers[b] * inNumbers[c];
								if (r == op4) {
									y[0] = std::to_string(inNumbers[a]);
									y[1] = std::to_string(inNumbers[b]);
									y[2] = std::to_string(inNumbers[c]);
									result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
									return result;
								}
							}
						}
					}

				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";

				if (op2 % inNumbers[2] == 0) {
					int op5 = op2;
					op5 = op5 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Sum).
					r = 0;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op5) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";

				if (op2 - inNumbers[2] > 0) {
					int op6 = op2;
					op6 = op6 / inNumbers[2];
					y[2] = std::to_string(inNumbers[2]);
					result += "(" + y[2] + "*";

					//Try per 2 number (Multiply).
					r = 1;
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 2 || b == 2 || a == 3 || b == 3 || a == 4 || b == 4) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b];
							if (r == op6) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "*" + y[1] + ")))";
								return result;
							}
						}
					}
				}
				result = result.substr(result.length());
				result += "(" + y[4] + "+";
			}
			result = result.substr(result.length());
			//---------------------------------------------------------------------------//
			op = reach;
			if (op % inNumbers[3] == 0) {
				int op3 = op;
				op3 = op3 / inNumbers[3];
				y[3] = std::to_string(inNumbers[3]);
				result += "(" + y[3] + "*";


				//Try per 2 number (Sum).
				r = 0;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (a == 3 || b == 3) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] + inNumbers[b];
						if (r == op3) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "+" + y[1] + "))";
							return result;
						}
					}
				}
				//Try per 3 number (Sum).
				r = 0;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						for (int c = 0; c < 6; c++) {
							if (a == 3 || b == 3 || c == 3) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b] + inNumbers[c];
							if (r == op3) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								result += "(" + y[2] + "+(" + y[0] + "+" + y[1] + ")" + ")))";
								return result;
							}
						}
					}
				}
			}
			result = result.substr(result.length());
			//---------------------------------------------------------------------------//
			op = reach;
			if (op - inNumbers[3] > 0) {
				int op4 = op;
				op4 = op4 - inNumbers[3];
				y[3] = std::to_string(inNumbers[3]);
				result += "(" + y[3] + "+";



				//Try per 2 number (Multiply).
				r = 1;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (a == 3 || b == 3) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] * inNumbers[b];
						if (r == op4) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "*" + y[1] + ")))";
							return result;
						}
					}
				}
				//Try per 3 number (Multiply).
				r = 1;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						for (int c = 0; c < 6; c++) {
							if (a == 3 || b == 3 || c == 3) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[b] == inNumbers[c]) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b] == inNumbers[c]) {
								continue;
							}
							r = inNumbers[a] * inNumbers[b] * inNumbers[c];
							if (r == op4) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								y[2] = std::to_string(inNumbers[c]);
								result += "(" + y[2] + "*(" + y[0] + "*" + y[1] + ")" + ")))";
								return result;
							}
						}
					}
				}

			}
			result = result.substr(result.length());
			//---------------------------------------------------------------------------//
			op = reach;
			if (op % inNumbers[2] == 0) {
				int op5 = op;
				op5 = op5 / inNumbers[2];
				y[2] = std::to_string(inNumbers[2]);
				result += "(" + y[2] + "*";

				//Try per 2 number (Sum).
				r = 0;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (a == 2 || b == 2) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] + inNumbers[b];
						if (r == op5) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "+" + y[1] + ")))";
							return result;
						}
					}
				}
				r = 1;//(Sum)
				if (op5 - inNumbers[1] > 0) {
					int op7 = op5;
					op7 = op7 - inNumbers[1];
					y[1] = std::to_string(inNumbers[1]);
					result += "(" + y[1] + "*";
					result += "(" + y[1] + "*";
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 2 || b == 2) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op7) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "5" + y[1] + ")))";
								return result;
							}
						}
					}
				}

			}
			result = result.substr(result.length());
			//---------------------------------------------------------------------------//
			op = reach;
			if (op - inNumbers[2] > 0) {
				int op6 = op;
				op6 = op6 / inNumbers[2];
				y[2] = std::to_string(inNumbers[2]);
				result += "(" + y[2] + "*";

				//Try per 2 number (Multiply).
				r = 1;
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (a == 2 || b == 2) {
							continue;
						}
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] * inNumbers[b];
						if (r == op6) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "*" + y[1] + ")))";
							return result;
						}
					}
				}
				r = 0;//(Sum)
				if (op6 % inNumbers[1] == 0) {
					int op7 = op6;
					op7 = op7 / inNumbers[1];
					y[1] = std::to_string(inNumbers[1]);
					result += "(" + y[1] + "*";
					for (int a = 0; a < 6; a++) {
						for (int b = 0; b < 6; b++) {
							if (a == 2 || b == 2) {
								continue;
							}
							if (inNumbers[a] == inNumbers[b]) {
								continue;
							}
							r = inNumbers[a] + inNumbers[b];
							if (r == op7) {
								y[0] = std::to_string(inNumbers[a]);
								y[1] = std::to_string(inNumbers[b]);
								result += "(" + y[0] + "+" + y[1] + ")))";
								return result;
							}
						}
					}
				}
			}
			result = result.substr(result.length());

			r = 1;//(Multiply)
			if (op % inNumbers[1] == 0) {
				int op7 = op;
				op7 = op7 / inNumbers[1];
				y[1] = std::to_string(inNumbers[1]);
				result += "(" + y[1] + "*";
				for (int a = 0; a < 6; a++) {
					for (int b = 0; b < 6; b++) {
						if (inNumbers[a] == inNumbers[b]) {
							continue;
						}
						r = inNumbers[a] * inNumbers[b];
						if (r == op7) {
							y[0] = std::to_string(inNumbers[a]);
							y[1] = std::to_string(inNumbers[b]);
							result += "(" + y[0] + "*" + y[1] + ")))";
							return result;
						}
					}
				}
			}
			return error;

		}
	
	};
}

// namespace SelimCeylan
