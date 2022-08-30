import GenericStatCard from "./GenericStatCard"

type Props = {
  tds: number
}

const TdsStatCard = ({
  tds
}: Props) => {
  return (  
    <GenericStatCard
      title="TDS Value"
      subtitle={tds < 500 ? "The water is clean." : "Please change the water."}
      number={tds}
      quantifier="ppm"
      isOptimal={tds < 500}
    >
      {/* <div className="flex flex-col w-full">
        <button className="bg-transparent text-left text-red-500 font-medium hover:text-red-600">
          Do nothing
        </button>
      </div> */}
    </GenericStatCard>      
  ) 
}

export default TdsStatCard