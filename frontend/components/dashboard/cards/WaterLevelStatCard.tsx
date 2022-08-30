import GenericStatCard from "./GenericStatCard"

type Props = {
  waterLevel: number
}

const WaterLevelStatCard = ({
  waterLevel
}: Props) => {
  return (  
    <GenericStatCard
      title="Water level"
      subtitle={waterLevel <= 60 ? "Water level is low." : "Water level is ok."}
      number={waterLevel}
      quantifier="%"
    >
    </GenericStatCard>      
  ) 
}

export default WaterLevelStatCard