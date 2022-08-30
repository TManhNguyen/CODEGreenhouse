import GenericStatCard from "./GenericStatCard"

type Props = {
  humidity: number
}

const HumidityStatCard = ({
  humidity
}: Props) => {
  return (  
    <GenericStatCard
      title="Humidity"
      subtitle="Humidity is optimal."
      number={humidity}
      quantifier="%"
      isOptimal={true}
    >
      {/* <div className="flex flex-col w-full">
        <button className="bg-transparent text-left text-blue-500 font-medium hover:text-blue-600">
          Release internal air
        </button>
      </div> */}
    </GenericStatCard>      
  ) 
}

export default HumidityStatCard