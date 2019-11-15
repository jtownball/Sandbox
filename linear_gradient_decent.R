require(radx)
# Gradient Decent Linear Regression
# y = mx + c
# define an error function
# find partial w.r.t m
# find partial w.r.t c
# this is effectively the del operator acting on a scalar function
# D_m is the derivative w.r.t m
# D_c is w.r.t. c
# the point derivative points in the directions if steepest assent
# the negative of the gradient is the direction of greatest descent


D_m <- function(m, x, y_a, y_p)
{
  d_m <- 0
  for(i in seq_along(x))
  {
    d_m <- x[i]*(y_a[i] - y_p[i])
  }
  d_m <- -2/length(x) * d_m
  return(d_m)
}

D_c <- function(c, y_a, y_p)
{
  d_c <- 0
  for(i in seq_along(x))
  {
    d_c <- (y_a[i] - y_p[i])
  }
  d_c <- -2/length(y_a) * d_c
  return(d_c)
}

update.function <- function(m, c, x, y_a, y_p, learning.rate)
{
  m <- m - learning.rate * D_m(m, x, y_a, y_p)
  c <- c - learning.rate * D_c(c, y_a, y_p)
  ret <- list(m, c)
  ret
}

error.function <- function(y_a, y_p)
{
  require(magrittr)
  E <- ((y_a - y_p)^2 %>% sum()) / length(y_a)
  E
}

vals <- update.function(3, 2, x, y_a, y_p, learning.rate = .01)

m <- .01
c <- 0
y_a <- cars$dist
x <- cars$speed
y_p <- m*x + c 

error.function(y_a, y_p)

error.level <- 100

while(error.function(y_a, y_p) > error.level)
{
  current.error <- error.function(y_a, y_p)
  vals <- update.function(m, c, x, y_a, y_p, learning.rate = .00001)
  m <- vals[[1]] %>% as.numeric()
  c <- vals[[2]] %>% as.numeric()
  y_p <- m*x + c 
  next.error <- error.function(y_a, y_p)
  if(next.error > current.error)
  {
    print("error level converged to")
    print(current.error)
    m <- mp
    c <- cp
    y_p <- m*x + ca
    break
  }
  mp <- m
  cp <- c
}

plot(cars)
lines(x = cars$speed, y = y_p, col = "red")
lmodel <- lm(dist ~ speed, data = cars)
y.model <- lmodel$coefficients[2] * cars$speed + lmodel$coefficients[1]
lines(x = cars$speed, y = y.model, col = "blue")
error.function(cars$dist, y.model)
error.function(y_a, y_p)

