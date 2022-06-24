#pragma once
#include <iostream>
using namespace std;
namespace mtmath
{
	// MY_DEBUG ����������
	//#define MY_DEBUG 
	template<typename T, int N, int M>
	struct MasWrapper
	{
		T mas[N][M];
	};

	template<typename T, int N, int M>
	class Matrix
	{
	public:
		// �����������
		Matrix()
		{
#ifdef MY_DEBUG
			std::cout << "Constructor" << std::endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = 0;
		}

		// �����������
		Matrix(const T mas[N][M])
		{
#ifdef MY_DEBUG
			std::cout << "Constructor" << std::endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mas[i][j];
		}

		// �����������
		Matrix(const MasWrapper<T, N, M>& mas)
		{
#ifdef MY_DEBUG
			std::cout << "Constructor" << std::endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mas.mas[i][j];
		}

		// ����������� �����������
		Matrix(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "Copy constructor" << std::endl;
#endif

			m_n = mat.m_n;
			m_m = mat.m_m;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.m_mat[i][j];
		}

		int getN() const { return m_n; }
		int getM() const { return m_m; }
		T get(int i, int j) const { return m_mat[i][j]; }
		void set(int i, int j, T data) { m_mat[i][j] = data; }

		// ������������
		template<typename T, int N, int M>
		Matrix<T, N, M>& operator=(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "Operator =" << std::endl;
#endif

			m_n = mat.getN();
			m_m = mat.getM();

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.get(i, j);

			return *this;
		}

		// �������� ��������
		template<typename T, int N, int M>
		Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "operator+" << std::endl;
#endif
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			return tmp;
		}
		// �������� ���������
		template<typename T, int N, int M>
		Matrix<T, N, M> operator-(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "operator-" << std::endl;
#endif
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
			return tmp;
		}

		// �������� ���������
		template<typename T, int N, int M>
		Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat)
		{
#ifdef MY_DEBUG
			std::cout << "operator*" << std::endl;
#endif
			Matrix<T, N, M> tmp;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < mat.getM(); j++)
				{
					T sum = 0;
					for (int k = 0; k < m_m; k++)
						sum += m_mat[i][k] * mat.get(k, j);
					tmp.set(i, j, sum);
				}

			return tmp;
		}
		//������� ���� ������� ��������
		Matrix <T, N, 1> SLAY()
		{

#ifdef MY_DEBUG
			cout << "���� �������" << endl;
#endif


			T d = determforSlay();
			if (d == 0)
			{
				cout << "������������ ����� 0 " << endl;
			}

			Matrix<T, N, 1> Answer;

			if ((m_m - 1) == m_n)
			{

				for (int swapJ = 0; swapJ < m_m - 1; swapJ++)

				{
					Matrix<T, N, M> newMatrix = m_mat;
					for (int i = 0; i < m_n; i++)
					{
						for (int j = 0; j < m_m - 1; j++)
						{
							if (swapJ == j) {
								newMatrix.m_mat[i][j] = m_mat[i][m_m - 1];
							}

						}

					}
					Answer.set(swapJ, 0, newMatrix.determforSlay() / d);

				}
				return Answer;
			}
			if ((m_m - 1) != m_n)
			{
				std::cout << "������. �������� ������� ���� ������ �� 1, ��� �����" << std::endl;

			}
		}

		// ������ ������������ ������� 
		T determ()
		{

			if (m_n == m_m)
			{
				T y;
				T p = 0;

				for (int i = 0; i < m_n - 1; i++)
				{
					int t = 1;
					while (m_mat[i][i] == 0)
					{
						for (int j = 0; j < m_m; j++)
						{
							m_mat[i][j] = y;
							m_mat[i][j] = m_mat[i + t][j];
							m_mat[i + t][j] = y;
						}
						p++;
						t++;
					}

					for (int k = i + 1; k < m_n; k++)
					{
						y = m_mat[k][i] / m_mat[i][i];
						for (int j = 0; j < m_n; j++)
							m_mat[k][j] -= m_mat[i][j] * y;
					}
				}

				y = pow(-1, p);
				for (int i = 0; i < m_n; i++)
					y *= m_mat[i][i];
				return y;
			}

			// ������� ������������

		}
		//����������������� �������
		Matrix<T, N, M> trans()
		{
			Matrix<T, N, M> tmp;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[j][i] = m_mat[i][j];
			return tmp;
		}


		//�������� �������
		Matrix<T, N, M> inv()
		{
			Matrix<T, N, M> tmp;

			//������
			int d = determ();
			if (d == 0) {
				cout << "�������� �� �������������� (������������ ����� 0)";
				return m_mat;
			}
			else {
				if ((m_n == 2) && (m_m == 2)) {
					tmp.m_mat[0][0] = m_mat[1][1] / d;
					tmp.m_mat[0][1] = -m_mat[0][1] / d;
					tmp.m_mat[1][0] = -m_mat[1][0] / d;
					tmp.m_mat[1][1] = m_mat[0][0] / d;
					return tmp;
				}
				else if ((m_n == 3) && (m_m == 3)) {
					tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / d;
					tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / d;
					tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / d;
					tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / d;
					tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / d;
					tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / d;
					tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / d;
					tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / d;
					tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / d;
					return tmp;
				}
				else {
					cout << "�������� �� ���������(������� �� 2 �� 2 � �� 3 �� 3" << endl;
				}
				return tmp;
			}
		}
	
		~Matrix()
		{
#ifdef MY_DEBUG
			std::cout << "Destructor" << std::endl;
#endif
		}

		// friend - ��������� ������� ����� ������ � private �����/������� ������
		template<typename T, int N, int M>
		friend std::istream& operator>>(std::istream& os, Matrix<T, N, M>& mat);

		template<typename T, int N, int M>
		friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& mat);

	private:
		int m_n, m_m;
		T m_mat[N][M];

		//������������ ��� �������
		T determforSlay() {
			Matrix<T, N, M> tmp = m_mat;
			if (m_n == (m_m - 1))
			{
				T y;
				T p = 0;

				for (int i = 0; i < m_n - 1; i++)
				{
					int t = 1;
					while (tmp.m_mat[i][i] == 0)
					{
						for (int j = 0; j < m_n; j++)
						{
							tmp.m_mat[i][j] = y;
							tmp.m_mat[i][j] = m_mat[i + t][j];
							tmp.m_mat[i + t][j] = y;
						}
						p++;
						t++;
					}

					for (int k = i + 1; k < m_n; k++)
					{
						y = tmp.m_mat[k][i] / tmp.m_mat[i][i];
						for (int j = 0; j < m_n; j++)
							tmp.m_mat[k][j] -= tmp.m_mat[i][j] * y;
					}
				}

				y = pow(-1, p);
				for (int i = 0; i < m_n; i++)
					y *= tmp.m_mat[i][i];
				return y;
			}

			if (m_n != (m_m - 1))
			{
				std::cout << "������" << m_n << (m_m - 1) << std::endl;
				return -1;
			}

		}
	};
	
	// ���������� ��������� �����
	template<typename T, int N, int M>
	std::istream& operator>>(std::istream& in, Matrix<T, N, M>& mat)
	{
		for (int i = 0; i < mat.m_n; i++)
			for (int j = 0; j < mat.m_m; j++)
				in >> mat.m_mat[i][j];
		return in;
	}

	// ���������� ��������� ������
	template<typename T, int N, int M>
	std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mat)
	{
		out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
		for (int i = 0; i < mat.m_n; i++) {
			for (int j = 0; j < mat.m_m; j++)
				out << mat.m_mat[i][j] << " ";
			out << std::endl;
		}
		return out;
	}
	using Vec2i = Matrix<int, 2, 1>;	// ����������� ������� ��������
	using Vec2d = Matrix<double, 2, 1>;
	using Mat22i = Matrix<int, 2, 2>;
	using Mat22d = Matrix<double, 2, 2>;
	using Mat33i = Matrix<int, 3, 3>;
	using Mat34d = Matrix<double, 3, 4>;
}