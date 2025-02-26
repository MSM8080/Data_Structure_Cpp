#ifndef Series_Header
#define Series_Header

class Series
{
private:
	float x;
protected:
	float sum;		    // sum of series terms
	float term_val;		// the last evaluated term
	int term_ind;		// term index
public:
	Series(float x_);
	void firstTerm()=0;
	void addNextTerm()=0;
	float getSeriesValue();
	float getCurrentTerm();
} 

#endif