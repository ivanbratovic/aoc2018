# Loading the tidyverse packages
library(tidyverse)
# Setting working directory
setwd("~/Documents/adventOfCode/2018/2")

# Part 1:

# Reading input
input <- read.csv("input.txt", stringsAsFactors = F)
# Splitting IDs into letters
table <- lapply(input, function(x){str_split(x," ")})$boxID
# Counting the numbers of letters that appear two or three times
# IDs that contain both are coded with a 5
lapply(table, function(x){
  table(x) %>% as.vector %>% .[.==2 | .==3] %>% unique %>% sum
}) %>% unlist %>% table
###############
#   Output:   #
###############
#   2   3   5 #
# 221   2  27 #
###############
(221+27)*(2+27)
# Part 2:

# 250x250 matrix to hold all the intersecting strings
intersectMatrix <- matrix(rep("",(250*250)),nrow=250,ncol=250)
# ...and a 250x250 matrix to hold all their lengths
intersectMatrixLength <- matrix(rep(0,(250*250)),nrow=250,ncol=250)

# Turning the input from a data frame to a vector
unlist(input) %>% as.vector -> input

# Function that compares two character vectors
# Returns the characters in common as a character string
strcmp <- function(x,y){
  stopifnot(is.character(x))
  stopifnot(is.character(y))
  stopifnot(length(x) == length(y))
  # Return value
  helper <- character();
  # Compare each character
  for (index in 1:length(x)) {
    if(x[index] == y[index]){
      # Append to return value if equal
      helper <- c(helper, as.character(x[index]))
    }
  }
  paste(helper,collapse = "")
}

# This pains me, but I couldn't think of any other solution
# Won't even comment the following code because I don't encourage reading it
# Don't look at it for too long :(
for (i in 1:250) {
  x <- strsplit(input[i], " ") %>% unlist
  for (j in 1:250) {
    y <- strsplit(input[j], " ") %>% unlist
    intersectMatrix[i,j] <- strcmp(x,y)
    intersectMatrixLength[i,j] <- nchar(intersectMatrix[i,j])
    if(paste(x, collapse = "") == paste(y, collapse = "")){
      intersectMatrix[i,j] <- "SAME"
      intersectMatrixLength[i,j] <- 0
    }
    maxMatrix <- max(intersectMatrixLength)
    if(intersectMatrixLength[i,j] == maxMatrix){
      cat("Current maximum:", maxMatrix, "Output string:", intersectMatrix[i,j])
    }
  }
}


