## Put comments here that give an overall description of what your
## functions do

## Write a short comment describing this function

# The following functions are used to create a special object that stores a matrix and caches its inverse. 

# The function below, makeCacheMatrix creates a special “matrix”, which is really a list containing a function to:
      
# set the value of the matrix

# get the value of the matrix

# set the value of the inverse

# get the value of the inverse

makeCacheMatrix <- function(x = matrix()) {
      
      k <- NULL
      set <- function(y) {
            x <<- y
            k <<- NULL
      }
      get <- function() x
      setinverse <- function(inverse) k <<- inverse
      getinverse <- function() k
      list(set = set, get = get,
           setinverse = setinverse,
           getinverse = getinverse)

}


## Write a short comment describing this function

# The function below computes the inverse of the special “matrix” returned by makeCacheMatrix above. 
# If the inverse has already been calculated (and the matrix has not changed), 
# then cacheSolve should retrieve the inverse from the cache.

cacheSolve <- function(x, ...) {
        ## Return a matrix that is the inverse of 'x'
      
      k <- x$getinverse()
      if (!is.null(k)) {
            message("getting cached data")
            return(k)
      }
      data <- x$get()
      k <- solve(data, ...)
      x$setinverse(k)
      k
}

## Sample Test 

# create the matrix
r <- matrix(c(45,55,65,75),2,2)
res <- makeCacheMatrix(r)
cacheSolve(res) 

cacheSolve(res)
