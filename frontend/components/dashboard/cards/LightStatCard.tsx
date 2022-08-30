import GenericStatCard from "./GenericStatCard"

type Props = {
  light: number
}

const LightLevelStatCard = ({
  light
}: Props) => {
  return (  
    <GenericStatCard
      title="Light exposure"
      subtitle={ light > 300 ? "Light exposure good." : "Light exposure is too low."}
      number={Math.round(light)}
      quantifier="lux"
      isOptimal={light > 300}
    >
      {/* <div className="flex flex-col w-full">
        <button className="bg-transparent text-left text-red-500 font-medium hover:text-red-600">
          Do nothing
        </button>
      </div> */}
    </GenericStatCard>      
  ) 
}

export default LightLevelStatCard