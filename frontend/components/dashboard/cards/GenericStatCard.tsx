import { useState } from "react"
import { CountUp } from "use-count-up"

type Props = {
  title: string,
  subtitle: string,
  number: number|string,
  quantifier: string,
  isOptimal?: boolean,
  children?: React.ReactNode
}

const GenericStatCard = ({
  title,
  subtitle,
  number,
  quantifier,
  isOptimal,
  children,
}: Props) => {
  return (  
    <div className="flex flex-col gap-y-2 p-4 w-full rounded bg-white">
      <dt className="font-medium text-gray-500">{title}</dt>
      <dd className={`text-5xl font-bold ${isOptimal ? "text-green-600" : "text-red-600"}`}>
        { typeof number === "number" ? (
          <CountUp isCounting={true} end={number} duration={0.5} /> 
        ) : (
          number
        ) }
        <span className={`text-xl ml-2 ${isOptimal ? "text-green-500" : "text-red-500"}`}>{quantifier}</span>
      </dd>
      <dt className="font-medium text-gray-500">{subtitle}</dt>
      {children}
    </div>
  ) 
}

export default GenericStatCard