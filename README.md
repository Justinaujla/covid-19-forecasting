🦠 COVID-19 Forecasting 
=======================

An exploration into forecasting and approximation theory to predict COVID cases one "time-step" into the future. Given only `n` data points at regularly spaced intervals, this project aims to find a model that can best predict the next value at one interval in the future.

The Methods Investigated
-------------------------

- [ ] **_Using the Lastest Datum_**
- [ ] **_Extrapolating from Polynomial Interpolation_**
 	 - [ ] Linear Interpolating Polynomials
  	- [ ] Centered Interpolating Polynomials
  	- [ ] Backward Interpolating Polynomials
- [ ] **_Approximation Theory_**
  	- [ ] Linear Least-Squares Best-Fit Polynomial
  	- [ ] Quadratic Least-Squares Best-Fit Polynomial
- [ ] **_Time Series Forecasting_**
	- [ ] ARIMA

Table of Contents
=================
+ 👋🏽 [Introduction](#-introduction)
	+ [What is forecasting?](#what-is-forecasting)
	+ [Why is forecasting important?](#why-is-forecasting-important)
	+ [How is this related to COVID?](#how-is-this-related-to-covid)
	+ [What is "noise"?](#what-is-noise)
+ 💡 [Theory Behind The Methods](#-theory-behind-the-methods)
	+ [Latest Datum](#latest-datum)
	+ [Polynomial Interpolation](#polynomial-interpolation)
		+ [Linear](#linear)
  		+ Centered
  		+ Backward
	+ Approximation using least-squares
		+ Linear
		+ Quadratic
	+ Time Series
		+ ARIMA
+ 🔨 Model Results
+ 📚 Furthur reading
+ 😷 Closing

👋🏽 Introduction
===============

What is forecasting?
----------------------
Forecasting is the process of making future predictions based on applying trend analysis to past and present data.


Why is forecasting important?
----------------------
From your local weather station to the stock market, forecasting is used everywhere. Forecasting helps us use the past to make better-informed choices about the future; for example, predicting the temperature in a few hours helps you decide if you should bring that sweater along.


How is this related to COVID?
-----------------------------
Just like the weather or stocks, being able to predict trends in COVID cases helps us, the government, and supply chains better prepare for what's to come. In the not-so-distant past, we saw how surges in cases had direct impacts on consumer behaviour (panic buying and overstocking) which caused enormous strains on supply chains.

Forecasting helps give a glimpse into the future so we can ready ourselves&mdash;whether that be with planning a lockdown, getting more medical equipment, or installing item limits.


What is "noise"?
----------------------
You can think of noise pretty much how you probably already think of it and how Oxford defines it:
> ## noise
> <b>a sound, especially one that is loud or unpleasant or that causes disturbance.</b>  </br>
> <i>"making a noise like a pig in a trough"<i>  </br>
> 
> <h6> &mdash; Oxford Languages </h6>

More specifically, in data science, noise pertains to the stability of the data. Less noisy data will have fewer disturbances and little fluctuation between datum. More noisy data, like COVID cases, will have large disturbances and can swing wildly and unpredictably from one value to another. The degree of variability in datum, or that swing, is the amount of noise.

If you look at any graph of new cases for COVID-19, it's pretty easy to notice that there is plenty of noise. This is the result of day-to-day anomalies. The noise itself can sometimes be as large as 10% or more. Because of this, it's a pretty terrible idea to use the most recent datum as a predictor for what is actually happening, or what will happen next.



💡 Theory Behind The Methods
=============================

Latest Datum
-------------
The latest datum method does exactly what it sounds like, it returns the value at time t<sub>n</sub> as the prediction for the value at time t<sub>n+1</sub>. This model, although the easiest, is also the worst. Because of this, we'll use this method as a threshold for unacceptable methods. Any method that performs worse than this will be discarded as a viable option.

The section [What is "noise"](#what-is-noise) covered why this method is never a good option, so I will reiterate it here again.

> Looking at any graph of new cases for COVID-19, it's pretty easy to notice that there is plenty of noise. This is the result of day-to-day anomalies. Because of this, it's a terrible idea to use the most recent datum as a predictor.

Polynomial Interpolation
-------------------------

### Constant
Since COVID cases are noisy data, let's try and clean up all the extra non-sense by smoothing out those jagged edges. A noise minimization technique you've probably heard about in some form or another is the seven or 10-day moving average. Many COVID-19 reports will include an average of the last seven or 10-days to show a clear picture of trends in cases. Although great at showing those trends, this is a pretty terrible predictor of the future for the following reason.

Consider the following noise-free data:
`10, 10, 10, 10, 10, 10, 9, 8, 6, 4`

From this, the 10-day average gives the value of **_8.7_**, and even if noise is introduced, the average will roughly remain 8.7. But now for the bad news. Let's assume that the next noise-free datum is **_3_**, how well would this 10-day average predict the next time-step value? Well, if the 10-day average is 8.7 at time t<sub>n</sub> then if we extrapolate to time t<sub>n+1</sub>, the average will still be 8.7. Compared to our true value of 3 that gives an approximate 66% relative error. Frankly, it does a terrible job, but this is expected.

From one of your high-school courses, you should know that the 10-day average is the best-fitting curve when you are trying to fit the zeroth degree polynomial **_y = a<sub>0</sub>_** to the data. The seven or 10-day average is a good estimator if the underlying signal is constant, but COVID cases are **not** constant. Because of this, if there are any significant changes, the seven or 10-day average will lag behind.

### Linear
Linear interpolation is a well known method of curve fitting for first degree polynomials of the form **_y = a<sub>1</sub>x + a<sub>0</sub>_**. Using discrete sets of data points we can construct linear polynomials to find new data points within the set's range.

Given the data points, <img src="http://latex.codecogs.com/svg.latex?\left(x_{k-1}\&space;,\&space;f\left(x_{k-1}\right)\right)\&space;and\&space;\left(x_{k\&space;},\&space;f\left(x_{k}\right)\right)" title="http://latex.codecogs.com/svg.latex?\left(x_{k-1}\ ,\ f\left(x_{k-1}\right)\right)\ and\ \left(x_{k\ },\ f\left(x_{k}\right)\right)" /> Theinterpolating polynomial will be <img src="http://latex.codecogs.com/svg.latex?\frac{f\left(x_{k}\right)-f\left(x_{k-1}\right)}{x_{k}-x_{k-1}}x&plus;\frac{f\left(x_{k-1}\right)x_{k}-f\left(x_{k}\right)x_{k-1}}{x_{k}-x_{k-1}}" title="http://latex.codecogs.com/svg.latex?\frac{f\left(x_{k}\right)-f\left(x_{k-1}\right)}{x_{k}-x_{k-1}}x+\frac{f\left(x_{k-1}\right)x_{k}-f\left(x_{k}\right)x_{k-1}}{x_{k}-x_{k-1}}" />
