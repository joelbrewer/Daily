async function main() {
  // ContractFactory is an abstraction used to deploy new smart contracts
  const BrewskiNFT = await ethers.getContractFactory("BrewskiNFT")

  // Start deployment, returning a promise that resolves to a contract object
  const brewskiNFT = await BrewskiNFT.deploy()
  await brewskiNFT.deployed()
  console.log("Contract deployed to address:", brewskiNFT.address)
}

main()
  .then(() => process.exit(0))
  .catch((error) => {
    console.error(error)
    process.exit(1)
  })
  
