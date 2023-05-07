# The director of a prison offers 100 death row prisoners, 
# who are numbered from 1 to 100, a last chance. A room 
# contains a cupboard with 100 drawers. The director randomly 
# puts one prisoner's number in each closed drawer. The prisoners 
# enter the room, one after another. Each prisoner may open and 
# look into 50 drawers in any order. The drawers are closed again 
# afterwards. If, during this search, every prisoner finds their 
# number in one of the drawers, all prisoners are pardoned. If even 
# one prisoner does not find their number, all prisoners die. Before 
#the first prisoner enters the room, the prisoners may discuss 
# strategy — but may not communicate once the first prisoner enters to 
# look in the drawers. What is the prisoners' best strategy?


# This function takes the list of drawers and the current prisoner number.
# It then follows the strategy to check the drawers.
prisonerStrategy <- function(listOfDrawers, currentPrisonerNumber)
{
  nextDrawerInSequence <- listOfDrawers[currentPrisonerNumber]
  for(prisonerNumber in 1:50)
  {
    if(nextDrawerInSequence == currentPrisonerNumber)
    {
      return(TRUE)
    }
    nextDrawerInSequence <- listOfDrawers[nextDrawerInSequence]
  }
  return(FALSE)
}

listOfPrisoners <- 1:100
# simCount controls how many times we see if all the prisoners live or die
# Set this value lower for a quicker response, and higher for more accuracy
simCount <- 100000 
listOfSimulationResults <- rep(0, simCount)
for(simulationIteration in 1:simCount)
{
  drawers <- sample(c(1:100), 100)
  LiveOrDie <- rep(0, 100)
  for(prisonerNumber in listOfPrisoners)
  {
    if(prisonerStrategy(drawers,prisonerNumber))
    {
      LiveOrDie[prisonerNumber] <- 1
    }
  }
  if(sum(LiveOrDie) == 100)
  {
    listOfSimulationResults[simulationIteration] <- 1
  }
}

# This prints the average of the simulation results
# The higher the number of simulation runs the closer
# to ~0.31183 the value should get
print(mean(listOfSimulationResults))

