import GenericStatCard from "./GenericStatCard"

type Props = {
  temperature: number
}

const TemperatureStatCard = ({
  temperature
}: Props) => {
  return (  
    <GenericStatCard
      title="Temperature"
      subtitle="Optimal temperature reached."
      number={temperature}
      isOptimal={true}
      quantifier="°C"
    >
      {/* <div className="font-medium text-gray-400 italic">
        No available action
      </div> */}
    </GenericStatCard>
  ) 
}

export default TemperatureStatCard