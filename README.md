COVID-19 Forecasting
=======================

An exploration into forecasting and approximation theory to predict COVID cases one "time-step" into the future. Given only `n` data points at regularly spaced intervals, this project aims to find a model that can best predict the next value at one interval in the future.

### The Methods Investigated

- [ ] **_Using the Lastest Datum_**
- [ ] **_Extrapolating from Polynomial Interpolation_**
  - [ ] Linear Interpolating Polynomials
  - [ ] Centered Interpolating Polynomials
  - [ ] Backward Interpolating Polynomials
- [ ] **_Approximation Theory_**
  - [ ] Linear Least-Squares Best-Fit Polynomial
  - [ ]	Quadratic Least-Squares Best-Fit Polynomial
- [ ] **_Time Series Forecasting_**
	- [ ] ARIMA
	- [ ] TBAT

The Background
-------------

If you look at any graph of new cases for COVID-19, it's pretty easy to notice that there is a ton of noise. This is the result of day-to-day anomalies. The noise itself can sometimes be as large as 10% or more. Because of this, it's a pretty terrible idea to use the most recent datum as a predictor for what is actually happening, or what will happen next.


The Obvious Solution
---------------------

To minimize this noise, many COVID-19 reports will include an average of the last seven or ten days. Although somewhat better, this is a pretty terrible predictor of the future for the following reason.

Consider the following noise-free data:
`10, 10, 10, 10, 10, 10, 9, 8, 6, 4`

If **_4_** is the most recent datum, a 10-day average gives the value of **_8.7_**. One benefit is that if we introduce noise the average will roughly remain 8.7. But now for the bad news. Let's assume that the next noise-free data point is **_3_**, how well would this 10-day average predict the next time-step value? Frankly, not really well&mdash;we'll look into this a little bit further down, but for now just take my word. From one of your high-school courses, you should know that the 10-day average is the best-fitting curve when you are trying to fit the zeroth degree polynomial **_y = a<sub>0</sub>_** to the data. The seven or 10-day average is a good estimator if the underlying signal is constant, but COVID cases are **not** constant. Because of this, if there are any significant changes, the seven or 10-day average will lag behind. This is fine if the goal is to remove noise and show a trend, but for forecasting&mdash;not so much. Nonetheless, this is just theory, so it will still be tested.
