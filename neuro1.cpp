#include <iostream>
#include <cmath>

class Unit {
    int n;
    double sum, offset, limit;
    double *w;
    void add(double *arr, double offset) {
        if (offset != 0)
            set_offset(offset);
        for (int i = 0; i < this->n; ++i) {
            this->sum += this->w[i] * arr[i];
        }
        this->sum += offset;
    }
public:
    Unit(int n, double *w, double offset, double limit=0) {
        this->sum = 0;
        this->n = n;
        this->w = new double[n];
        set_weights(w);
        set_offset(offset);
        this->limit = limit;
    }
    void set_offset(double offset) {
        this->offset = offset;
    }
    void set_weights(double *w) {
        for (int i = 0; i < this->n; ++i) {
            this->w[i] = w[i];
        }
    }
    void set_limit(double limit) {
        this->limit = limit;
    }
    double step(double *arr, double offset=0) {
		if (offset) set_offset(offset);
        add(arr, this->offset);
        return this->sum > this->limit;
    }
    double sigma(double *arr, double t=1, double offset=0) {
		if (offset) set_offset(offset);
        add(arr, this->offset);
        return 1 / (1 + exp(-sum / t));
    }
    double viewstep() {
        return this->sum > this->limit;
    }
    double viewsigma(double t=1) {
        return 1 / (1 + exp(-sum / t));
    }
    void clear() {
		this->sum = 0;
	}
};

int main() {
    int n, m, t;
    double offset;
    std::cout << "Temperature: ";
    std::cin >> t;
    std::cout << "Offset: ";
    std::cin >> offset;
    std::cout << "Number of inputs: ";
    std::cin >> n;
    double *a1 = new double[n];
    for (int i = 0; i < n; ++i)
        std::cin >> a1[i];
    Unit u(n, a1, offset);
    //u.step(a1);
    double ai[n];
    std::cout << "Number of elements: ";
    std::cin >> m;
    /*for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			std::cin >> ai[j][i];
		}
	}*/
    //for (int i = 0; i < m; ++i) std::cin >> ai[i];
    u.clear();
    for (int j = 0; j < m; ++j) {
		u.clear();
		for (int i = 0; i < n; ++i) std::cin >> ai[i];
		std::cout << u.step(ai) <<  '\n';
		u.clear();
	}
	// std::cout << u.viewstep();
	u.clear();
    //std::cout << u.sigma(ai, t) << "\n";
    return 0;
}